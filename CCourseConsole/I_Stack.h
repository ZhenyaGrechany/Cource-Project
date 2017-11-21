#pragma once
template<class item>
class I_Stack
{
public:

	virtual void pushBack(item item) = 0;
	virtual item pop() = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;

	virtual ~I_Stack()
	{
	}
};

