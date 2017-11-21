#pragma once

class I_Logger
{
public:

	virtual void openResourse() = 0;
	virtual void outputInfo(const char *str) = 0;
	virtual void closeResourse() = 0;

	virtual ~I_Logger()
	{
	}
};

