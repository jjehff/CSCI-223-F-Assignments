// ============================================================================
// File: binfile.c (Spring 2024)
// ============================================================================
// This program reads a binary file of records containing phone numbers and
// corresponding room numbers. It derives the number of records contained in
// the binary file and allocates an array of structures of that size. Then it
// opens the binary file and reads all the data into the dynamic array with a 
// single call to "fread". Once the data has been read, the user is prompted 
// for a filename, which is used to create a text file, and the records are 
// written to the output file formatted for human consumption.
// ============================================================================

#include    <ctype.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>


// defined constants
#define BUFLEN          256
#define DAT_FNAME       "records.dat"


// structure declarations
typedef struct  PhoneRoom
{
    int         phone;
    int         room;

} PhoneRoom;



// function prototypes
void    WriteRecs(const PhoneRoom  recs[], int  numRecs, FILE*  fPtr);


// ==== main ==================================================================
// 
// ============================================================================

int     main(void)
{
    // open the input file that contains the binary records
	FILE *inFile = fopen(DAT_FNAME, "r");
	
	
    // calculate the number of records stored in the file and display the total
    // to stdout
	fseek(inFile, 0, SEEK_END); // Move position in file to the end
	auto int numRecs = ftell(inFile) / sizeof(PhoneRoom); // Line above allows ftell to return the end of file
	printf("There is a total of %d records in the \"records.dat\"\n", numRecs);
	rewind(inFile); // Move position back to the beginning

    // allocate an array of records large enough to hold all of the data
	PhoneRoom* records = malloc(numRecs * sizeof(PhoneRoom));
	if (records == NULL) {
		printf("Memory alloc failed\n");
		return 0;
	}
	

    // read all the file records into the allocated buffer
	fread(records, sizeof(PhoneRoom), numRecs, inFile);
	

    // get the name of the output file from the user and open it
    auto char fileName[BUFLEN];
	printf("Enter the name of the output fiel: ");
	scanf("%c", fileName);
	FILE* outFile = fopen(fileName, "w");

    // call WriteRecs to write out the records in formatted text
	WriteRecs(records, numRecs, outFile);
	printf("%d records written to %s\n", numRecs, fileName);

	
    // close the files and release allocated memory
	fclose(inFile);
	fclose(outFile);
	free(records);

    return 0;

}  // end of "main"



// ==== WriteRecs =============================================================
// 
// This function writes the contents of the PhoneNum array to the output stream
// pointed to by the fPtr parameter. The binary data is formatted for human 
// eyes as the records are written to the output stream.
// 
// Input:
//      recs        -- the base address of an array of PhoneNum records
// 
//      numRecs     -- the number of elements in the array
// 
//      fPtr        -- a pointer to the output stream to which the records
//                     are written
// 
// Output:
//      Nothing.
// 
// ============================================================================

void    WriteRecs(const PhoneRoom  recs[], int  numRecs, FILE*  fPtr)
{
	if (fPtr == NULL) {
		printf("Error opening file\n");
		exit(0);
	}
	for (int i = 0; i < numRecs; i++) {
		char temp[BUFLEN];
		sprintf(temp, "%03d-%04d", recs[i].phone / 10000, recs[i].phone % 10000); // Convert to string format because I couldnt get any other way to work
		fprintf(fPtr, "Phone: %s", temp);
		fprintf(fPtr, " Room#: %d\n", recs[i].room);
	}
}  // end of "WriteRecs"
