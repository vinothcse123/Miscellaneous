
#include<iostream>

int mf(int p[55]) // Received size is 2
{
   printf("\n Will be called with any error ???");
}

int main()
{
   int a[2];
   mf(a); // Passing an invalid size array

   return 0;
}

