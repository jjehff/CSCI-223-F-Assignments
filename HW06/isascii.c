#include <stdio.h>

int main(void) {
	auto int bit, offset = 0, ascii = 0, nonascii = 0;
	while (EOF != (bit = getchar())) {
		if (bit & 0x80) {
			nonascii++;
			printf("NON-ASCII INPUT %X detected at offset Ox%X\n", bit, offset);
			offset++;
		}
		else {
			ascii++;
			offset++;
		}
	}
	if (nonascii == 0) {
		printf("The input stream was pure ASCII with a total of %d bytes read.\n", ascii);
	}		
	else {
		printf("A total of %d non-ASCII bytes were encountered.\n", nonascii);
	}
}
