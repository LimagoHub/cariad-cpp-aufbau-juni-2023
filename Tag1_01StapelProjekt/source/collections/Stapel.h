#pragma once
#include "StapelException.h"
namespace collections
{

	class Stapel
	{
	public:
		int data[10];
		int index{ 0 };


		bool is_empty() const noexcept;
		bool is_full() const noexcept;

		void push(int value);
		int pop();

	};

}