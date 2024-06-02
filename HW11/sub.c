#include <stdio.h>
#include "sub.h"

void SubInts(int int1, int int2) {
	auto int subbed = int1 - int2;
	printf("The difference is %d\n", subbed);
}
