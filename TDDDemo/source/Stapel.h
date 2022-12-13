#pragma once

class Stapel {
	bool empty{ true };
public:
	bool is_empty()
	{
		return empty;
	}

	void push(int value)
	{
		empty = false;
	}
};
