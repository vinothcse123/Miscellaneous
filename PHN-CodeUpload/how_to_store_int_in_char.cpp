
#include<iostream>


int main()
{
   int i=123456789;

   char a[5]={0};

   memcpy(a, (&i), sizeof(int) );

   a[5]=0;


   int b=0;
   memcpy(&b,a,4);

   printf("\n  :: %u ", sizeof( int ) );

   printf("\n  :: %s ", a );

   printf("\n  :: %d ", b );


   return 0;
}
