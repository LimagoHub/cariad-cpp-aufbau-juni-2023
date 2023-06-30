#pragma once
#include <string>


#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../io/Writer.h"
class Mockwriter : public Writer
{
public:
	MOCK_METHOD(void, write, (const std::string &message), (const override));
};