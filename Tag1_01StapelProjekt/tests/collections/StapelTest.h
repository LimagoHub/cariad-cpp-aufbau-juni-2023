#pragma once
#include "gtest/gtest.h"
#include "../../source/collections/Stapel.h"
#include "../../source/collections/StapelException.h"
using namespace testing;

namespace collections {

    class StapelTest : public Test {
    
    protected:
        Stapel objectUnderTest;

    	void fillUpToLimit()
    	{
            for (int i = 0; i < 10; ++i)
            {
                EXPECT_NO_THROW(objectUnderTest.push(1));
            }
    	}
    };



}