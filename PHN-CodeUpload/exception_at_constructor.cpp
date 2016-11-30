
#include<iostream>

class ArrayNotFound
{
   public:
      ArrayNotFound()
      {
         std::cout<<"C"<<std::endl;
         throw 12;
      }

      void operator delete(void * p)
      {
         std::cout<<"Good Bye!" <<std::endl;
      }

      ~ArrayNotFound()
      {
         std::cout<<"D"<<std::endl;
      }
};

int main()
{
   try
   {
      ArrayNotFound *ptr=new ArrayNotFound;

   }
   catch(...)
   {
      std::cout<<"Exception";
   }

   return 0;
}


