#include "basedemo.h"
#include <iostream>

namespace CppInterview{

class ClassDemo : public BaseDemo
{
    public:
    virtual void demo()override
    {
        std::cout<<"Welcome to class demo\n";
        RuleOfFive().demo();
    }

    private:
    class RuleOfFive: public BaseDemo
    {
        public:
        virtual void demo()override
        {
            std::cout<< "   You shall implement these 5 if you managing dynamic memory\n";
            std::cout<< "   copy constructor\n";
            std::cout<< "   copy assignment operator\n";
            std::cout<< "   destructor\n";
            std::cout<< "   move constructor\n";
            std::cout<< "   move assignment operator\n";
        }

    };


    
};

}