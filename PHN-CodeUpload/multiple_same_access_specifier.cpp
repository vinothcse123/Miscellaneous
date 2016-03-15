#include<iostream>

struct base
{
   public:
      virtual void call()=0;
   public:
      int a;

};

struct der
{
   virtual void call()
   {
      printf("\n called");
   }
};

int main()
{
   der d;
   d.call();

   return 0;
}

