
#include<iostream>

void callme(int (&arrayAsReference)[10])
{
   printf("\n  :: %u ", sizeof(arrayAsReference) );
}

int main()
{
   int a[10];
   callme(a);

   return 0;
}

