
#include<iostream>

class grandparent
{
   virtual void myvirtualFunc();
};

class parent : grandparent
{
};

class child : parent
{
   virtual void newVirtualFunc();
};


int main()
{

   printf("\n  :: %u ", sizeof( child  ) );

   return 0;
}

