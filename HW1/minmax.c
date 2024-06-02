#include <stdio.h>

int main(void) {
	auto int max, min, currentInt, temp = 0;
	while(1) {
		printf("Enter an integer or EOF to quit >> ");
		if (scanf("%d", &currentInt) != 1 || currentInt == EOF) {
			printf("Terminating program..\n");
			break;
		}
		else {
			if (temp == 0) {
				min = currentInt;
				max = currentInt;
				temp++;
			}
			if (currentInt > max) {
				max = currentInt;
			}
			else if (currentInt < min) {
				min = currentInt;
			}
			else if (currentInt == EOF) {
				break;
			}
		}
	}
	if (temp == 0) {
		printf("No valid integers entered\n");
	}
	else {
		printf("Minimum Integer: %d\nMaximum Integer: %d\n", min, max);
	}
}
