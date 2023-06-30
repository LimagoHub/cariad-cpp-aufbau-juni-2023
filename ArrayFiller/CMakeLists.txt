cmake_minimum_required(VERSION 3.25)
project(ArrayFiller)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArrayFiller main.cpp src/bootstrap/application_starter.h src/client/array_client.h src/container/array_factory.h src/generators/generator.h src/generators/number_generator.h src/generators/random/mersenne_twister_number_generator.h src/generators/number_generator_factory.h src/generators/random/mersenne_twister_number_generator_factory.h src/container/sequential/array_factory_sequencial_impl.h src/container/parallel/array_factory_parallel_impl.h src/time/stopwatch.h src/time/stopwatch_impl.h src/time/decorator.h)
