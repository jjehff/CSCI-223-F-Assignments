#include <stdio.h>
void MakeChange();

int main(void) {
	auto int pennies, dollars, halfDollars, quarters, dimes, nickels;
	printf("Please enter the total number of pennies: "); 
	if (scanf("%d", &pennies) != 1) {
		printf("Invalid input");
	}
	else {
		MakeChange(&dollars, &halfDollars, &quarters, &dimes, &nickels, &pennies);
		printf("Here is the currency equivalent:\n%d dollars\n%d half dollars\n%d quarters\n%d dimes\n%d nickels\n%d pennies\n", dollars, halfDollars, quarters, dimes, nickels, pennies);
	}
}

void MakeChange(int *dollars, int *halfDollars, int *quarters, int *dimes, int *nickels, int *pennies) {
	*dollars = *pennies / 100;
	*pennies %= 100;
	*halfDollars = *pennies / 50;
	*pennies %= 50;
	*quarters = *pennies / 25;
	*pennies %= 25;
	*dimes = *pennies / 10;
	*pennies %= 10;
	*nickels = *pennies / 5;
	*pennies %= 5;
}
