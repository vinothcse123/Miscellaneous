#include<iostream>

template<int a>
class test
{
   public:
   static void callme()
   {
      printf("\n  :: %d ", a  );
   }

   static void hi()
   {
      callme();
   }
};

int main()
{
   test<5>::hi();

   return 0;
}

