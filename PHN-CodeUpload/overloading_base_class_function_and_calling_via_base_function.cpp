#include<iostream>

struct base
{
   int b;
   void basef()
   {
      this->cf();
   }

   base(int a){}

   virtual void cf()=0;
   virtual void ddddd()=0;
   virtual ~base(){}
};

struct der:public base
{
   int d;

   virtual void ddddd()
   {

   }

   void virtual cf()
   {
      printf("\n cf derived");
   }

   der():base(10){}
};


int main()
{
   der d;
   d.basef();
   d.cf();


   return 0;
}
