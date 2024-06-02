#include <stdio.h>

int main(void) {
	auto int c, count = 0, line = 1, validity = 0;
	while (EOF != (c = getchar())) {
		if (c == '\n') {
			if (count > 80) {
				printf("Line %d has %d characters\n", line, count);
				validity = 1;
			}
			line++;
			count = 0;
		}
		else {
			count++;
		}
	}
	if (validity == 0) {
		printf("The input file is valid\n");
	}
	
}
