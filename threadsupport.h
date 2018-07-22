#include <iostream>
#include <thread>
#include <condition_variable>

#include "basedemo.h"

namespace CppInterview{

    class ThreadSupport : public BaseDemo
    {
        public:
        virtual void demo()override
        {
            std::cout<<"Welcome to thread support demo\n";
            StartThread().demo();
            ConditionDemo().demo();
        }   

        private:
        class StartThread: public BaseDemo
        {
            public:
            virtual void demo() override
            {
                std::cout<<"Hi from thread: " << std::this_thread::get_id()<<std::endl;
                
                auto f = [](){std::cout<<"Hi from thread :" << std::this_thread::get_id()<<std::endl;};
                auto t = std::thread(f);     
                t.join();

            }
        };

        class ConditionDemo: public BaseDemo
        {
            public:
            std::condition_variable condition;
            std::mutex m;
            std::string shared_data;
            bool ready = false;
            bool processed = false;
            
            virtual void demo() override
            {
                std::cout<<"Demo of condition variable" << std::this_thread::get_id()<<std::endl;
                shared_data = "Before";
                auto l = [&]()
                {
                    std::cout<<"Hi from thread" << std::this_thread::get_id()<<std::endl;
                    std::unique_lock<std::mutex> lk(this->m);
                    condition.wait(lk,[&]{return this->ready;});
                    std::cout<<"Now starting processing\n";
                    this->shared_data += " - after";
                    processed = true;

                    std::cout<<"done with processing\n";
                    lk.unlock();
                    condition.notify_one();
                };  
                std::thread worker(l);
                {
                    std::unique_lock<std::mutex> lk(this->m);
                    ready = true;
                    std::cout<<"Will signal to working thread now\n";
                }
                condition.notify_one();
                {
                    std::unique_lock<std::mutex> lk(this->m);
                    condition.wait(lk, [&]{return processed;});
                }
                std::cout << "Back in main(), data = " << shared_data.c_str() << '\n'; 
                worker.join();
           }
        };
       
    };

}