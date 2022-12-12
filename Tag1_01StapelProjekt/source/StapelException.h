#pragma once

#include <stdexcept>

class StapelException : public std::out_of_range
{
public:
	StapelException(const std::string& _Message)
		: out_of_range(_Message)
	{
	}

	StapelException(const char* _Message)
		: out_of_range(_Message)
	{
	}
};

