#include<iostream>

class A
{
   public:
      void myMember(){};
};

int main()
{
   A obj;

   void (A::*ptrToMemberFunc)()=&A::myMember;


   return 0;
}


