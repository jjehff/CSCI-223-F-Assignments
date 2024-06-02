// ============================================================================
// File: mthreads01.c (Spring 2024)
// ============================================================================
// This version just works with two threads.
// ============================================================================

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <pthread.h>


// function prototypes
void*   ThreadFunc(void  *vptr);


// ==== main ==================================================================
//
// ============================================================================

int     main(int  argc, char  **argv)
{
    auto    unsigned long       counter = 0;
    auto    unsigned long       primaryMsecs;
    auto    unsigned long       secondMsecs;
    auto    pthread_t           threadID;

    // verify the argument count
    if (argc != 3) {
    	puts("usage: ./mt1 <#primary microseconds> <#secondary microseconds>");
    	exit(1);
    }

    // convert the string arguments to integers for the primary microseconds
    // and the secondary microseconds
	if (sscanf(argv[1], "%lu", &primaryMsecs) != 1) {
		printf("Error converting %s into an integer...\n", argv[1]);
		exit(1);
	}
	if (sscanf(argv[2], "%lu", &secondMsecs) != 1) {
		printf("Error converted %s into an integer...\n", argv[2]);
		exit(1);
	}
    // call 'pthread_create' to create the secondary thread, passing the
    // secondary thread's microseconds interval as an argument
    pthread_create(&threadID, NULL, ThreadFunc, (void*)&secondMsecs);

    // launch the primary thread loop
    while (1)
        {
        printf("Primary thread at %lu microseconds, counter = %lu...\n"
                                                    , primaryMsecs, counter);
        usleep(primaryMsecs);
        ++counter;
        }

    return 0;

}  // end of "main"



// ==== ThreadFunc ============================================================
// 
// This is the thread function for the secondary thread. The caller provides a
// pointer to an unsigned long that contains the number of microseconds to
// pause between messages. The value is fetched using the parameter, then an
// inifinite loop is entered that displays messages that the secondary thread
// is executing.
//
// Input:
//     vptr [IN]    -- a void pointer to an unsigned long that contains the
//                     number of microseconds to pause on each loop iteration
//
// Output:
//     A NULL pointer; this is never actually returned because the loop for the
//     secondary thread is inifinite!
// 
// ============================================================================

void*	ThreadFunc(void  *vptr)
{
	auto unsigned long *pauseTime = (unsigned long *)vptr;
	auto int count = 0;
	while (1) {
		printf("Secondary thread at %lu microseconds, counter = %d\n", *pauseTime, count++);
		usleep(*pauseTime);
	}

}  // end of "ThreadFunc"
