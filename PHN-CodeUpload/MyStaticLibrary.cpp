
/* /usr/sfw/bin/g++ -c MyStaticLibrary.cpp
 * ar -rvs MyStaticLibrary.a MyStaticLibrary.o
 *
 * r - Create and modify archive fiels
 * v- print version number
 * s - update the symbol table
 *
 *
 * usr/sfw/bin/g++ exploreme.cpp  -lMyStaticLibrary (or)
 * usr/sfw/bin/g++ exploreme.cpp  libMyStaticLibrary.a
 *
 */

#include  <iostream>

int callme()
{
   printf("\n Library called V1.0");
   printf("\n Library called V2.0");
}


