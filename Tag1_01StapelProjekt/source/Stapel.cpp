#include "Stapel.h"
#include "StapelException.h"

Stapel::Stapel() :index(0)
{
}

void Stapel::push(int value)
{
	if (is_full()) throw StapelException{ "Overflow" };
	data.push_back(value);
}

int Stapel::pop()
{
	if (is_empty()) throw StapelException{ "Underflow" };
	int result = data.back();
	data.pop_back();
	return result;
	
}
bool Stapel::is_empty() const
{
	return  data.empty();
}
bool Stapel::is_full() const
{
	return data.size() >= 10;
}