                     volatile_member_function.cpp

#include<iostream>

class MyClass
{

   public:
      int a;
      void callme()
      {
         std::cout<<"Called";
      }
};

int main()
{

   MyClass volatile a;
   a.callme();

   return 0;
}


