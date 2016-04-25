#include<iostream>

struct base
{
   int a:2;
   unsigned int :0;
   int c;
};



int main()
{

   printf("\n  :: %d ", sizeof( base ) );

   return 0;
}
