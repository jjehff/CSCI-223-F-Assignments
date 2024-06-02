#include <stdio.h>
#include <string.h>

int main(void) {
	int check = strspn("abcxyz", "abxyz");
	printf("%d", check
	);
}
