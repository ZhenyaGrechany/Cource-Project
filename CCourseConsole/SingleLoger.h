#pragma once
class SingleLoger
{
public:
	void logOut(const char *Str);
private:
	SingleLoger() {};
	SingleLoger& operator=(const SingleLoger &obj) = delete;
public:
	static SingleLoger& getInstance();
};

