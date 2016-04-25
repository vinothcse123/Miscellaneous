#include<iostream>
/* Normal macros are replaced as such, but function like macros does not do this */
#define callmyfunc() realfunc()
#define callmyfunc_wp(a,b,c) realfunc(a)

void realfunc()
{
   printf("\n Real function called");
}

void realfunc(int a)
{
   printf("\n Real function with parameter called");
}

int main()
{
   callmyfunc();
   callmyfunc_wp(1,2,3);

   return 0;
}

