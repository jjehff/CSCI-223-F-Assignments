#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void) {
	auto int int1, int2;
Check:
	printf("Enter the first integer ");
	if (scanf("%d", &int1) != 1) {
		goto Check;
	}
	else {
		printf("Enter the second integer ");
		if (scanf("%d", &int2) != 1) {
			goto Check;
		}
		else {
			AddInts(int1, int2);
			SubInts(int1, int2);
		}
	}
	
	
}
