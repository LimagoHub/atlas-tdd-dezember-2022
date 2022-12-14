#pragma once
#include "Translator.h"
#include <memory>


class TranslatorClient
{
	// IOC Inversion of Control	// DI Dependency Injection
	
public:
    TranslatorClient(std::unique_ptr<Translator> translator) : translator_(std::move(translator)) {}

    void go()
	{
		std::cout << translator_->translate("Hallo") << std::endl;
	}
private:
	std::unique_ptr<Translator> translator_;
};
