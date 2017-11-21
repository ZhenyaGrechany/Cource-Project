#pragma once
class ArrMult
{
public:
	ArrMult(int mult);
	~ArrMult();

	void Mult(int *pAr,int nSize);

private:
	int multiplier;
};

