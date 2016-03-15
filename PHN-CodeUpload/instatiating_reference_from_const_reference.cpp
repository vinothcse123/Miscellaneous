#include<iostream>
#include <map>

struct base
{
   int b;
};

struct der: public base
{
   int d;
};

int main()
{

   int a=10;
   const int &r1=a;
//    int &r2=r1; Not allowed


   return 0;
}
