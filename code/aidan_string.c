#include <stdio.h>
#include <stdlib.h>

typedef struct aidan_string
{
	int length;
	int bytes;
	char *string;
} aidan_string;

int cstringlength(char *string)
{
	int result = 0;
	while(string[result] != '\0')
	{
		result++;
	}

	return(result);
}

aidan_string *init_empty_aidan_string(int bytes)
{
	aidan_string *result = (aidan_string *) malloc((sizeof *result));
	result->length = 0;
	result->bytes = bytes;
	result->string = (char *) malloc((sizeof *(result->string))*bytes);

	return(result); 
}

void free_aidan_string(aidan_string *aidan_string_struct)
{
	if(aidan_string_struct != 0)
	{
		free(aidan_string_struct->string);
		free(aidan_string_struct);
	}
}

int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);
	for(int i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	aidan_string program_name = {0};
	program_name.length = cstringlength(argv[0]);
	program_name.string = argv[0];

	aidan_string* test_string = 0;
	test_string = init_empty_aidan_string(10);
	free_aidan_string(test_string);

	return(0);
}
