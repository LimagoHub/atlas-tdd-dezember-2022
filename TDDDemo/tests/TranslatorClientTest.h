#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../source/Translator.h"
#include "../source/TranslatorClient.h"
#include <memory>
class TranslatorMock :public Translator
{
public:
	MOCK_METHOD(std::string, translate, (std::string), (const));
};

using namespace testing;

class TranslatorClientTest : public Test
{
protected:

    // Bei Unique-Pointern muss man den Inject in der Test-Methode durchführen

	std::unique_ptr<TranslatorMock> translatorMock = std::make_unique<TranslatorMock>();
	TranslatorClient object_under_test{std::move(translatorMock)};



};
