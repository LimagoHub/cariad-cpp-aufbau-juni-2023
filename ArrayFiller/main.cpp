#include <iostream>
#include <climits>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <memory>


using namespace std::chrono;

#define MAX_ARRAY_SIZE INT32_MAX/8

class Demo {

    std::shared_ptr<int[]> data;

//    static void foo(int time) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(time));
//    }

public:
    auto run() -> void  {

//        std::thread t1{&foo, 1000 };
//        t1.detach();
//        std::thread t2{&foo };
//        std::thread t3{&foo };
//        std::thread t4{&foo };
//
//        if(t1.joinable())
//            t1.join();
//        t2.join();
//        t3.join();
//        t4.join();

        data = std::shared_ptr<int[]>{new int[MAX_ARRAY_SIZE]};
        auto availableProcessors = std::thread::hardware_concurrency();
        std::cout << "Anzahl der Kerne = " << availableProcessors << std::endl;

        for (int i = 1; i <= availableProcessors + 1 ; ++i) {
            auto start = high_resolution_clock::now();

            for(int i = 0; i < MAX_ARRAY_SIZE; ++ i)
            {
                data[i] = rand();
            }

            auto ende = high_resolution_clock::now();
            std::cout <<  "Zeit: " << duration_cast<milliseconds>(ende - start).count() << " ms" << std::endl;

        }


    }

};


auto main() -> int{
    Demo demo;
    demo.run();
    return 0;
}
