#include <stdio.h>
#include <ctype.h>
int main(void) {
	auto char letters, rot13;
	while(1) {
		if (scanf(" %c", &letters) == EOF) {
			printf("Terminating program..\n");
			break;
		}
		else {
			if (isalpha(letters) == 0) { 
				printf("%c\n", letters);
			}
			else if (letters >= 110 || (letters >= 78 && letters <= 90)) {
				rot13 = letters - 13;
				printf("%c\n", rot13);
			}
			else {
				rot13 = letters + 13;
				printf("%c\n", rot13);	
			}
			//printf("%c\n", rot13);
		}
	}
	
}
