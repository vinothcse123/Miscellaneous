#include<iostream>

class OuterClass
{
   public:
   class InnerClass
   {

      public:
         int var;
         InnerClass()
         {
            var = 25;
         }

   };
};

template<typename T>
class MyClass
{
   public:
   typename T::InnerClass obj;

   MyClass()
   {
      std::cout<<"A"<<std::endl;
      std::cout<<obj.var<<std::endl;
   }
};

int main()
{
   MyClass<OuterClass> l_obj;


   return 0;
}

