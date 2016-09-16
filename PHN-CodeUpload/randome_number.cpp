
#include<iostream>


int main()
{
   srand(102);
   int a=rand()%100;


   srand(102);
   int b=rand()%100;

   if(a==b)
   {
      printf("\n Ya its same!");
   }
   else
   {
      printf("\n Oh no its not same!");
   }


   return 0;
}
