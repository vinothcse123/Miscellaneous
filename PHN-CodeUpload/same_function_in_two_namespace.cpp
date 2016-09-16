#include<iostream>

void callme()
{
   std::cout<< "1"  <<std::endl;
}
namespace myNameSpace
{
   void callme()
   {
      std::cout<< "2"  <<std::endl;
   }
}


int main()
{
   using namespace myNameSpace;
   callme();

   return 0;
}
