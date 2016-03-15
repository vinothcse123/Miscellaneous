#include<iostream>

struct base
{
   static int b:1;
};

int base::b=10;

int main()
{


   printf("\n  :: %d ", base::b );
   return 0;
}
