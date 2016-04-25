#include<iostream>

void callme(bool defaultvalue=false);

int main()
{
   callme();

   return 0;
}

void callme(bool defaultvalue=false)
{
   printf("\n called");
}

