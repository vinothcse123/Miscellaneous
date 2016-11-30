
#include<iostream>

class a
{

};

bool operator==(a obj,int a)
{
   return false;
}

int main()
{
   if(a() == 10)
   {
      printf("\n Same");
   }
   else
   {
      printf("\n Different");
   }
   return 0;
}

