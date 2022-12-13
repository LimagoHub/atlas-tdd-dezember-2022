#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../source/Translator.h"
#include "../source/TranslatorClient.h"
class TranslatorMock :public Translator
{
public:
	MOCK_METHOD(std::string, translate, (std::string), (const));
};

using namespace testing;

class TranslatorClientTest : public Test
{
protected:
	TranslatorMock translatorMock;
	TranslatorClient object_under_test{translatorMock};



};
