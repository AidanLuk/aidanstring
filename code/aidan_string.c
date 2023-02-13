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

	return(0);
}
