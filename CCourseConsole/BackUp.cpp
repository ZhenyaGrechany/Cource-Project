#include "stdafx.h"
#include "BackUp.h"


BackUp::BackUp()
{
}


BackUp::~BackUp()
{
}

int BackUp::Write(const char * sFileName, void * pData, int nBytes)
{
	FILE *fp;
	FILE *tmpfp;
	//
	fopen_s(&tmpfp,"tmpfile","w");
	if (tmpfp == NULL)
	{
		puts("Tmp file error");
		return 1;
	}
	size_t nWritten = fwrite(pData, 1, nBytes, tmpfp);		
	fclose(tmpfp);
	//

	//
	fopen_s(&fp, sFileName, "w");
	if (fp == NULL)
	{
		puts("File error");
		return 2;
	}

	size_t mainWritten = fwrite(pData, sizeof(int), nBytes, fp);
	fclose(fp);
	//

	if (mainWritten == nWritten)
	{
		remove("tmpfile");
		return 0;
	}
	else
	{
		return 3;
	}
}


void * BackUp::Read(const char * sFileName, int * pReadedBytes, int * pErrorCode)
{
	FILE * ptrFile;
	fopen_s(&ptrFile,sFileName, "rb"); // �������� ����� � ��������
	if (ptrFile == NULL)
	{
		puts("File error");
		*pErrorCode = 1;
		return nullptr;
	}


	long lSize;
	fseek(ptrFile, 0, SEEK_END);     //��������� � �����
	lSize = ftell(ptrFile);				// ������� �������� ����� �������
	rewind(ptrFile);				//��������� � ������                      


	char * buffer = (char*)malloc(sizeof(char) * lSize);   // ��������� ������ � �������� 
	if (buffer == NULL)
	{
		puts("Memory error");
		*pErrorCode = 2;
		return nullptr;
	}

	size_t result = fread(buffer, sizeof(char), lSize, ptrFile);       //result - ���������� ��������� ��������
	if (result != lSize)
	{
		puts("Read error");
		*pErrorCode = 3;
		return nullptr;
	}	

	///buffer[lSize] = '\0'; ///�� �����������������!!!

	fclose(ptrFile);

	*pReadedBytes = result;

	return (void *)buffer;
}
