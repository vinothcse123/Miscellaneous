#include<iostream>

class InputClass
{
   class InnerClass
   {

   };
};

template<typename T>
class MyClass
{
   public:
   T::InnerClass obj;

   MyClass()
   {
      std::cout<<"A"<<std::endl;
   }
};

int main()
{
   MyClass<InputClass> l_obj;


   return 0;
}
