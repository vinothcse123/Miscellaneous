
#include<iostream>

class test
{
   public:
      void callme()
      {
         std::cout<<"Called"<<std::endl;
      }
};

int main()
{
   void (test::*fptr)()=&test::callme;

   test t;
   (t.*fptr)();


   return 0;
}


