#pragma once
#include "Translator.h"

class TranslatorClient
{
	// IOC Inversion of Control	// DI Dependency Injection
	
public:
	TranslatorClient(Translator& translator)
		: translator_(translator)
	{
	}

	void go()
	{
		std::cout << translator_.translate("Hallo") << std::endl;
	}
private:
	Translator& translator_;
};
