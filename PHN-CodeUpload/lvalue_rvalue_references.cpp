
#include <iostream>

int main()
{
   int i=10,j=50;
   int &a=i;
   a=j;

   std::cout<<a<<std::endl;

   int &&lr=25;
   lr=63;

   std::cout<<lr<<std::endl;

}
