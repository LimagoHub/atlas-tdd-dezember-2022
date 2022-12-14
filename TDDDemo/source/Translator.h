#pragma once
#include <string>
class Translator
{
public:
    Translator() = default;
    virtual ~Translator() = default;

    virtual std::string translate(std::string message) const = 0;
};
