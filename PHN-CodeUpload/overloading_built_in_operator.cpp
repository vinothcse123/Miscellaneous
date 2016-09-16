#include<iostream>

int operator+(int a,int b)
{
   std::cout<<"A"<<std::endl;
}

int main()
{
   std::cout<<  5+10 <<std::endl;

   return 0;
}
