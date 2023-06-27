#include "Stapel.h"

using namespace collections;


bool Stapel::is_empty() const noexcept
{
	return data.empty();
}
bool Stapel::is_full() const noexcept
{
	return data.size() >= 10;
}

void Stapel::push(int value)
{
	if (is_full()) throw  StapelException{ "Overflow" };
	data.push_back(value);
}
int Stapel::pop()
{
	if(is_empty()) throw  StapelException{ "Underflow" };
	auto retval = data.back();
    data.pop_back();
    return retval;
}

Stapel::Stapel()  {
    data.reserve(10);
}
