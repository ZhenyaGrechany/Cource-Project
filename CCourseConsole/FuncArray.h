#pragma once
#include <iostream>

using namespace std;

int arrFunc()
{
	
	int nSize = 2, iCurInd = 0, a;
	int *pAr = new int[nSize];
	while (true)
	{
		cin >> a;

		if (a == 0)
			break;

		pAr[iCurInd++] = a;
		if (iCurInd == nSize)
		{
			int nNewSize = nSize + nSize / 2;
			int *pTemp = new int[nNewSize];
			memcpy(pTemp, pAr, sizeof(int) *nSize);
			delete[] pAr;
			cout << "old size = " << nSize << "new size = " << nNewSize << endl;
			pAr = pTemp;
			nSize = nNewSize;
		}
		
	}
	
	return *pAr;
}