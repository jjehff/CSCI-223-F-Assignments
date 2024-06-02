#include <stdio.h>
void PrintBox(int width, int height, char character);
void PrintChars(int width, char character, int height);

int main(void) {
	auto int width, height;
	auto char character;
	printf("Enter the width (Positive) >> ");
	if (scanf("%d", &width) != 1 || width < 0) {
		printf("Invalid integer. Terminating program..\n");
	}
	else {
		printf("Enter the height (Positive) >> ");
		if (scanf("%d", &height) != 1 || height < 0) {
			printf("Invalid integer. Terminating program..\n");
		}
		else {
			printf("Enter the character for the box >> ");
			scanf(" %c", &character);
			PrintBox(width, height, character);
		}
	}
}

void PrintBox(int width, int height, char character) {
	PrintChars(width, character, height);
}

void PrintChars(int width, char character, int height) {
	for (int i = 0; i < height; i++) {
		if (i == 0 || i == height - 1) {
			for	(int i = 0; i < width; i++) {
				printf("%c", character);
			}
			printf("\n");
		}
		else if (width == 1) {
			printf("%c\n", character);
		}
		else {
			printf("%c %*c\n", character, width-2, character);
		}
	}
}
