#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	if (argc != 2) {
		printf("Usage: cb <number> [h]\n");
		return 0;
	}
	else {
		auto char convert[255];
		(sscanf(argv[1], "%s", convert));
		int length = strlen(convert);
		if (strchr(argv[1], 'h') != NULL) {
    		for (int i = 0; i < length-1; i++) {
        		char c = convert[i];
        		if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
        			printf("Invalid input...\n");
            		return 0;
        		}
    		}
    		int temp;
    		sscanf(argv[1], "%x", &temp);
    		printf("%d\n", temp);
		}
		else {
			for (int i = 0; convert[i] != '\0'; i++) {
				if (!(convert[i] >= '0' && convert[i] <= '9')) {
					printf("Invalid input...\n");
					return 0;
				}
			}
			auto int base10;
			sscanf(argv[1], "%d", &base10);
			printf("%Xh\n", base10);
			
		}		
	}
}
