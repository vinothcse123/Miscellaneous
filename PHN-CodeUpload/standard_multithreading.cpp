
#include <iostream>
#include<thread>

void run()
{
   std::cout<<"Thread is called";
}

int main()
{
   std::thread t1(run);
   t1.join();
}

