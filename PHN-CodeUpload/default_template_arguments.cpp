
#include<iostream>

template<class T1,class T2=int,class T3=int>
void DefaultTemplateArguments(T1 a,T2 b,T3 c)
{
   printf("\n  a :: %d ",  a );
   printf("\n  b :: %d ",  b);
   printf("\n  c :: %d ",  c);
}

int main()
{


   return 0;
}
