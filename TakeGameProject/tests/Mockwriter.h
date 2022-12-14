#pragma once
#include <string>

#include "../source/IO/writer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class Mockwriter : public writer
{
public:
	MOCK_METHOD(void, write, (std::string), (const override));
};