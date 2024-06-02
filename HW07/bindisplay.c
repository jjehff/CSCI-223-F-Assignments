#include <stdio.h>

int main(void) {
	int value, temp = 0;
	while(1) {
		printf("Enter an integer value: ");
		if (scanf("%d", &value) != EOF) {
			for (int i = 31; i >= 0; i--) {
				int bit = (value >> i) & 1;
				printf("%d", bit);
				temp++;
				if (temp == 4) {
					printf(" ");
					temp = 0;
				}
			}
			printf("\n");
		}
		else {
			break;
		}
	}
}
