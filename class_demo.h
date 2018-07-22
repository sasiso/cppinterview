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
            RuleOfFive(bool print=false)
            {
                if(print)
                    std::cout<<"Inside c'tor\n";

            }
            virtual void demo()override
            {
                std::cout<<"----------------------------------\n\n";
                std::cout<< "   You shall implement these 5 if you managing dynamic memory\n";
                std::cout<< "   copy constructor\n";
                std::cout<< "   copy assignment operator\n";
                std::cout<< "   destructor\n";
                std::cout<< "   move constructor\n";
                std::cout<< "   move assignment operator\n";

                auto assign = RuleOfFive();

                std::cout<<"c'tor is called when new object is created\n\n";
                auto obj = RuleOfFive(true);

                std::cout<<"copy c'tor is called when old object is assigned from old\n\n";
                auto obj1 = obj;

                std::cout<<"assignment operator is called when old object is assigned from old\n\n";
                assign = obj1;

                auto  mv_obj1 = RuleOfFive();
                auto mv_obj2 = RuleOfFive();

                std::cout<<"Calling copy c'tor\n\n";
                auto obj2 = RuleOfFive(std::move(assign));

                std::cout<<"move assignment operator is called when old object is move from old\n\n";
                mv_obj1 = std::move(mv_obj2);

                std::cout<<"----------------------------------\n\n";

            }
            
            RuleOfFive(const RuleOfFive& other)
            {
                std::cout<<"Inside copy c'tor\n";
            }
            RuleOfFive& operator=(const RuleOfFive& other)
            {
                std::cout<<"Inside operator=\n";
                if (&other == this)
                    return *this;

                return *this;
            }
            ~RuleOfFive()
            {
                //std::cout<<"Inside d'tor\n";
            }

            RuleOfFive(RuleOfFive&&)
            {
                std::cout<<"Inside move c'tor\n";
            }

            RuleOfFive& operator=(const RuleOfFive&& other)
            {
                std::cout<<"Inside move  operator=\n";
                if (&other == this)
                    return *this;

                return *this;
            }            

        };        
    };

}