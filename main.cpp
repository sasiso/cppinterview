#include <iostream>
#include "class_demo.h"
#include "threadsupport.h"

using namespace CppInterview;

int main()
{
    std::cout<< "Welcome to C++ interview guide" << std::endl;
    ClassDemo().demo(); 
    ThreadSupport().demo();   

    return 0;
}
