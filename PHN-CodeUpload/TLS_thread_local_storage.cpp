
#include<iostream>
#include  <pthread.h>

int* getAddress(int p)
{
   static __thread int a=10;
   a=p;
   return &a;
}

void* run1(void *p)
{
   int *v=getAddress(10);
}

void* run2(void *p)
{
   int *v=getAddress(20);
}

int main()
{
   pthread_t t1,t2;
   pthread_create(&t1,NULL,run1,NULL);
   pthread_create(&t2,NULL,run2,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);

   return 0;
}
