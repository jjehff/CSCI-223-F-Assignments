#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 251
// ==== main ==================================================================
//
// ============================================================================
int main(void)
{
	auto char buf[BUFLEN];
	auto char *charPtr[BUFLEN];
	auto char* result;
	int total = 0;
		// get a string from the user into a local buffer
	while (total < 100) {
		printf("Please enter a string: ");
		result = fgets(buf, BUFLEN, stdin);
	// if we failed to get a string, exit the program
		if (NULL == result) {
			puts("main: fgets failed to read a string...");
			exit(EXIT_FAILURE);
		}
		if (strcmp(buf, "\n") == 0) {
            break;
		}													
		charPtr[total] = malloc(strlen(buf) + 1); 				
																
																
		if (NULL == charPtr[total]){
			puts("main: malloc failed...");
			exit(EXIT_FAILURE);
		}
			// copy the buffer over to the heap space
		strcpy(charPtr[total], buf);							
		total++;
	}
	for (int i = total - 1; i >= 0; i--) {
	        printf("%s", charPtr[i]);
	        free(charPtr[i]);  // Free allocated memory			
	    }
//	printf("main: stack string = %s", buf);
//	printf("main: heap string = %s", charPtr);
	// release the string from the heap
//	free(charPtr);
	return 0;
} // end of "main"
