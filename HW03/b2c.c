#include <stdio.h>

 /* int main(void) {
	auto int c;
	auto int buffer = 0;
	
	while (EOF != (c = getchar())) {
		// Print combined collected hex digits.
		// Clear the save buffer.
		if (c == ' ' || c == '\n') {
			printf("%c", buffer);
			buffer = 0;
		} else {
			// Convert 0-9.

			// Convert A-F.
		}
	}
}

8234A

c = '8' = 56 - 48 = 8
c = '9' = 57 - 48 = 9
c = 'A' = 65 - 55 = 10
c = 'B' = 66 - 55 = 11

0 * 10 + (c - 48) or 0 * 10 + (c - 55)

buffer * 10 + (c - 48) or buffer * 10 + (c - 55) */
int main() {
    auto int hex;
    while (EOF != scanf("%x", &hex)) {
        printf("%c", hex);
    }
}
