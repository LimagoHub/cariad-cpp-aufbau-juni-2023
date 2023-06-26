#pragma once


#include <exception>
namespace collections {
    class StapelException : public std::exception {
    public:
        StapelException() {}

        explicit StapelException(const char* const message) : exception(message) {}
    };
}
