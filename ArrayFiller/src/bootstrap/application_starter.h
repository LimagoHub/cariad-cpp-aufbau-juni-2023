//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once
#include <thread>
#include "../container/sequential/array_factory_sequencial_impl.h"
#include "../container/parallel/array_factory_parallel_impl.h"
#include "../generators/random/mersenne_twister_number_generator.h"
#include "../generators/random/mersenne_twister_number_generator_factory.h"
#include "../client/array_client.h"
#include "../time/decorator.h"



using namespace collections;
using namespace generators;
using namespace client;


class application_starter {




//    static auto create()-> int {
//        mersenne_twister_number_generator generator_;
//        array_factory_sequencial_impl<int> array_factory_{generator_};
//        array_client<int> client_{array_factory_};
//        client_.go();
//        return 0;
//    }

    static auto create(size_t threadCount)-> int {


        std::cout << "Messung mit " << threadCount << " Threads: " << std::endl;
        mersenne_twister_number_generator_factory generator_factory_;
        array_factory_parallel_impl<int> array_factory_{generator_factory_, threadCount};
        array_client<int> client_{array_factory_};
        client_.go();


        return 0;
    }

public:
    auto run()-> void {
        auto available_processors =  std::thread::hardware_concurrency();
        for (size_t threadCount = 1; threadCount <= available_processors + 1 ; ++threadCount) {
            auto ex = make_decorator(create);
            ex(threadCount);
        }
    }

};
