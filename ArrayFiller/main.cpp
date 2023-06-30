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
public:
    auto run() -> void  {

        data = std::shared_ptr<int[]>{new int[MAX_ARRAY_SIZE]};
        auto availableProcessors = std::thread::hardware_concurrency();
        std::cout << "Anzahl der Kerne = " << availableProcessors << std::endl;

        auto start = high_resolution_clock::now();

        for(int i = 0; i < MAX_ARRAY_SIZE; ++ i)
        {
            data[i] = rand();
        }

        auto ende = high_resolution_clock::now();
        std::cout <<  "Zeit: " << duration_cast<milliseconds>(ende - start).count() << " ms" << std::endl;


    }

};


auto main() -> int{
    Demo demo;
    demo.run();
    return 0;
}
