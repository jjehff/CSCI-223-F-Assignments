#include <string.h>
#include <stdio.h>

int mystrspn(const char* str, const char* accept);

int main(void) {
	auto char str[251];
	auto char accept[251];
	printf("Type in a string: ");
	scanf("%s", str);
	printf("Type in a string you want to compare with: ");
	scanf("%s", accept);
	auto int count = mystrspn(str, accept);
	printf("%d\n", count);
}

int mystrspn(const char* str, const char* accept) {
	auto int count = 0;
	auto int check = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		for(int j = 0; accept[j] != '\0'; j++) {
			if (str[i] == accept[j]) {
				count++;
				check = 1;
				break;
			}
		}
		if (check == 0) {
			return count;
		}
		else {
			check = 0;
		}
		
	}
	return count;
}
