#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DummyClassesForTest.h"
#include "../source/games/players/player.h"




class Mockplayer : public player<DummyBoard, DummyMove>
{
public:
	MOCK_METHOD(std::string, getName, (), (const, override));
	MOCK_METHOD(DummyMove, do_turn, (const DummyBoard& scene), (const, override));
};
