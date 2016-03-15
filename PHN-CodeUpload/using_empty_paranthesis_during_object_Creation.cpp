#include<iostream>

struct base
{
   int b;
};

int main()
{
   void callme();

   base bb();
   base *bptr= new base();

   bb.b=25;

   return 0;
}
