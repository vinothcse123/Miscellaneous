#include<iostream>


int main()
{
#ifndef ERROR_SIMULTATION
#error "ERROR_SIMULTATION is not defined as macro during compilation! It is required for compilation!!!"
#endif

   printf("\n This is compiled!!!");


   return 0;
}

/*
 *
 * g++ error_directive_simulation.cpp
 * g++ -DERROR_SIMULTATION error_directive_simulation.cpp
 *
 */


