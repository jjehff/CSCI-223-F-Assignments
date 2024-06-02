// ============================================================================
// File: mthreads02.c (Spring 2024)
// ============================================================================
// This version uses command line arguments to determine how many threads to 
// launch.
// ============================================================================

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <pthread.h>


// function prototypes
void*   ThreadFunc(void  *vptr);

// structure declarations
typedef
struct  ThreadInfo
{
    unsigned long       micros;
    unsigned int        threadNum;

} ThreadInfo;


// ==== main ==================================================================
//
// ============================================================================

int     main(int  argc, char  **argv)
{
    auto    unsigned long       pri_micros;
    auto    unsigned long       sec_micros;
    auto    pthread_t           threadID;
    auto    ThreadInfo          *infoPtr;
    auto    int                 counter;

    // verify the argument count
    if (argc < 3) {
    	puts("usage: ./mt2 <#primary microseconds> <thread #1 microseconds> <thread #2 microseconds>...\n");
    	exit(1);
    }

    // convert the string argument for the primary thread to an integer
    if (sscanf(argv[1], "%lu", &pri_micros) != 1) {
    	printf("Error converting %s into an integer...\n", argv[1]);
    	exit(1);
    }

    // loop and create any remaining secondary threads:
    // -- convert the msecs string argument to an unsigned long
    for (int i = 2; i < argc; i++) {
    	if (sscanf(argv[i], "%lu", &sec_micros) != 1) {
    		printf("Error converting %s into an integer...\n", argv[i]);
    	}
    	
		// -- allocate a ThreadInfo structure
		infoPtr = (ThreadInfo*)malloc(sizeof(ThreadInfo));
		if (infoPtr == NULL) {
			puts("Memory allocation failed\n");
			exit(1);
		}
	
		// -- store the thread ID and microseconds in the structure
		infoPtr->threadNum = i - 1;
		infoPtr->micros = sec_micros;
		
		// -- create secondary thread, passing ptr to structure
		pthread_create(&threadID, NULL, ThreadFunc, (void*)infoPtr);
	}
    // launch the primary thread loop
    while (1)
        {
        printf("Primary thread at %lu microseconds...\n", pri_micros);
        usleep(pri_micros);
        }

    return 0;

}  // end of "main"



// ==== ThreadFunc ============================================================
// 
// This is the thread function for the secondary thread. The caller provides a
// pointer to a ThreadInfo structure, which contains the thread number and the
// number of microseconds to wait between output messages. Once that information
// is fetched from the structure, an inifinite loop is entered that displays 
// messages that the current secondary thread is executing.
//
// Input:
//     vptr [IN]    -- a void pointer to a ThreadInfo structure
//
// Output:
//     A NULL pointer; this is never actually returned because the loop for the
//     secondary thread is inifinite!
// 
// ============================================================================

void*   ThreadFunc(void  *vptr)
{
    ThreadInfo *info = (ThreadInfo*) vptr;
    while(1) {
    	printf("Secondary thread #%d with %lu microseconds...\n", info->threadNum, info->micros);
    	usleep(info->micros);
    }
	
}  // end of "ThreadFunc"
