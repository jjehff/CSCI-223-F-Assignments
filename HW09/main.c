#include <stdio.h>
#include "dispoct.h"
#include "disphex.h"
int main(void) {
	int b10;
	printf("Please enter a base 10 integer: ");
	scanf("%d", &b10);

	DispOct(b10);
	DispHex(b10);
	
}
