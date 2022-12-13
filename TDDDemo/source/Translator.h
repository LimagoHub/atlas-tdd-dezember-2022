#pragma once
#include <string>
class Translator
{
public:
	virtual std::string translate(std::string message) const = 0;
};
