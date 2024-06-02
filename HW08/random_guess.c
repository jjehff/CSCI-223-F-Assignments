#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void FillRandArray();
int FindNumMatches();

int main(void) {
	int max, numElem = 1000000;
	srand(time(NULL));
	int arr[numElem];
	printf("What is the maximum random value? ");
	if (scanf("%d", &max) != 1) {
		printf("Invalid Input\n");
	}
	else {
		for (int i = 0; i < numElem; i++) {
			int random = rand() % max;
			arr[i] = random;
		}
		int targetValue;
		printf("What is the target value? ");
		if (scanf("%d", &targetValue) != 1) {
			printf("Invalid Input\n");
		}
		else {
			int matches;
			printf("How many matches do you think there will be? ");
			if (scanf("%d", &matches) != 1) {
				printf("Invalid Input\n");
			} 
			else {
				FillRandArray(arr, numElem, max);
				int results = FindNumMatches(arr, numElem, targetValue);
				printf("There were %d matches, meaning you were off by %d\n", results, abs(results - matches));
				
			}
		}
	}
}

void FillRandArray(int arr[], int numElem, int max)  {
	for (int i = 0; i < numElem; i++) {
		int random = rand() % (max + 1);
		arr[i] = random;
	}
}

int FindNumMatches(int arr[], int numElem, int targetValue) {
	int correct = 0;
	for (int i = 0; i < numElem; i++) {
		if (arr[i] == targetValue) {
			printf("arr[%d] = %d\n", i, arr[i]);
			correct++;
		}
		
	}
	return correct;
}
