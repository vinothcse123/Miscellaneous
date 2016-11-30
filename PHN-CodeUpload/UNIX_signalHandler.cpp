
#include<iostream>
#include <signal.h>

sigset_t g_signalSet;
struct sigaction g_sigActionStruct;

void mySigHandlerFunction(int)
{
   printf("\n Signal captured!");
}

int main()
{
   sigemptyset(&g_signalSet);
   sigfillset(&g_signalSet);


   /* Deleting the signal from signal set, so that the property going to set will not affect it */
   sigdelset(&g_signalSet, SIGABRT);
   pthread_sigmask(SIG_BLOCK, &g_signalSet, NULL); // Block all signals except SIGABRT

   pthread_sigmask(SIG_UNBLOCK, &g_signalSet, NULL);


   g_sigActionStruct.sa_handler = mySigHandlerFunction;
   sigaction(SIGINT, &g_sigActionStruct, NULL);


   return 0;
}

