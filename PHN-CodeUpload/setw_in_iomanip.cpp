
#include<iostream>
#include  <iomanip>

int main()
{
   int a=10;

   std::cout << std::setw(5) << std::setfill('x') << 9 << std::endl << std::setfill('y') << 8;

   return 0;
}
