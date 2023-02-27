#include <stdio.h>
#include <stdlib.h>

#define AIDAN_STRING_INITIAL_BYTES 32

typedef struct aidan_string
{
	int Length;
	int Bytes;
	char *String;
} aidan_string;

int CStringLength(char *String)
{
	int Result = 0;
	while(String[Result] != '\0')
	{
		Result++;
	}

	return(Result);
}

aidan_string *GrowAidanString(aidan_string *AidanString)
{
	while(AidanString->Length >= AidanString->Bytes)
	{
		AidanString->Bytes *= 2;

	}
	AidanString->String = realloc(AidanString->String, AidanString->Bytes);
	return AidanString;
}


aidan_string *InitEmptyAidanString(int Bytes)
{
	aidan_string *Result = (aidan_string *) malloc((sizeof *Result));
	Result->Length = 0;
	Result->Bytes = Bytes;
	Result->String = (char *) malloc((sizeof *(Result->String))*Bytes);

	return(Result); 
}

aidan_string *CStringToAidanString(char *CString)
{
	aidan_string *Result = InitEmptyAidanString(AIDAN_STRING_INITIAL_BYTES);
	int CStringIndex = 0;
	while(CString[CStringIndex] != '\0')
	{
		Result->String[Result->Length] = CString[CStringIndex];
		CStringIndex++;
		Result->Length++; 
		if (Result->Bytes <= Result->Length)
		{
			Result = GrowAidanString(Result);
		}
	}
	Result->String[Result->Length] = '\0';
	return Result;
}

void AppendAidanStringToAidanString(aidan_string *AidanString1, aidan_string *AidanString2)
{
	int AidanString1Index = AidanString1->Length;
	AidanString1->Length += AidanString2->Length;
	if(AidanString1->Length >= AidanString1->Bytes)
	{
		AidanString1 = GrowAidanString(AidanString1);
	}
	for(int AidanString2Index = 0; AidanString2Index < AidanString2->Length; AidanString2Index++, AidanString1Index++)
	{
		AidanString1->String[AidanString1Index] = AidanString2->String[AidanString2Index];
	}
	AidanString1->String[AidanString1->Length] = '\0';
}


void FreeAidanString(aidan_string *AidanString)
{
	if(AidanString != 0)
	{
		free(AidanString->String);
		free(AidanString);
	}
}

int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);
	for(int i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	aidan_string ProgramName = {0};
	ProgramName.Length = CStringLength(argv[0]);
	ProgramName.String = argv[0];

	aidan_string* test_string = 0;
	test_string = InitEmptyAidanString(10);
	FreeAidanString(test_string);

	aidan_string* test_string_2 = 0;
	test_string_2 = CStringToAidanString("Hello, this is a test to see if the function works");


	return(0);
}
