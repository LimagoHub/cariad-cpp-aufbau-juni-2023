#pragma once
#include "StapelException.h"
#include <vector>
namespace collections
{

	class Stapel
	{
	public:
		std::vector<int> data;


        explicit Stapel();

        bool is_empty() const noexcept;
		bool is_full() const noexcept;

		void push(int value);
		int pop();

	};

}