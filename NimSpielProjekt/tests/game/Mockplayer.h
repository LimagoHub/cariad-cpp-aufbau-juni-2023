#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DummyClassesForTest.h"
#include "../../game/player/player.h"


class Mockplayer : public player<DummyBoard, DummyMove>
{
public:
	MOCK_METHOD(std::string, get_name, (), (const, override));
	MOCK_METHOD(DummyMove, do_turn, (const DummyBoard& scene), (const, override));
};
