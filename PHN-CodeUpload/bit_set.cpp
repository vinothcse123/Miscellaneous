#include<iostream>
#include <bitset>
#include<sstream>



int main()
{
   std::bitset<8> l_bit_set;

   l_bit_set.set(4);

   std::stringstream s;
   s << l_bit_set;

   printf("\n  :: %s ", s.str().c_str() );

   return 0;
}

