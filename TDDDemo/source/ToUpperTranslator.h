#pragma once
#include "Translator.h"
#include <algorithm>
#include <string>
class ToUpperTranslator: public Translator
{
public:
	std::string translate(std::string message) const override
	{
		std::transform(message.begin(), message.end(), message.begin(), ::toupper);
		return message;
	}
};