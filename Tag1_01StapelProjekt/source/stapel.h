#pragma once
#include <vector>

class Stapel
{

	std::vector<int> data;
	int index;
public:
	Stapel();
	~Stapel() = default;
	
	

	void push(int value);
	int pop();

	bool is_empty()  const;
	bool is_full() const;
};
