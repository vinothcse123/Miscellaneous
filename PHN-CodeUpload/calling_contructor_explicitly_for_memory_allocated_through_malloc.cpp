#include<iostream>

struct a
{
   int obj;

   a()
   {
      obj=10;
   }
};

int main()
{
   a *ptr=(a*)malloc(sizeof(a));

   ptr=  new (ptr) a;

   printf("\n  :: %d ", ptr->obj );

   return 0;
}

