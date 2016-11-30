
#include<iostream>
#include "dlfcn.h"


int main()
{
   void *lib_ptr=dlopen("MyDynamicLibrary.so",RTLD_LAZY);

   if(!lib_ptr)
   {
      printf("\n Cannot open the library");
      char *errorMsg = dlerror();

      if(errorMsg)
         printf("\n  :: %s ",  errorMsg);
      return false;
   }

   int(*callme)();

   callme = (int(*)()) dlsym(lib_ptr,"callme");

   if(!callme)
   {
      printf("\n Cannot open the symbol");
      char *errorMsg = dlerror();

      if(errorMsg)
         printf("\n  :: %s ",  errorMsg);
      return false;
   }

   (*callme)();


   return 0;
}

