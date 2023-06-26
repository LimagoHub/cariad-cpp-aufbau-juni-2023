#include "Stapel.h"

using namespace collections;


bool Stapel::is_empty() const noexcept
{
	return index == 0;
}
bool Stapel::is_full() const noexcept
{
	return index >= 10;
}

void Stapel::push(int value)
{
	if (is_full()) throw  StapelException{ "Overflow" };
	data[index++] = value;
}
int Stapel::pop()
{
	if(is_empty()) throw  StapelException{ "Underflow" };
	return data[--index];
}
