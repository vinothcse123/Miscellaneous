#include <iostream>
using namespace std;

class A
{
   public:
      A(int n )  {cout << "constructor called \n " << n;}
   private:
};

void foo(const A a1){}

int main()
{
   foo(911);
   const A a=20;
   return 0;
}

