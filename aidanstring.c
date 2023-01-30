#include <stdio.h>
#include <stdlib.h>

typedef struct custom_string
{
	int length;
	int bytes;
	char *string;
} custom_string;

int cstringlength(char *string)
{
	int result = 0;
	while(string[result] != '\0')
	{
		result++;
	}

	return(result);
}

custom_string *init_empty_custom_string(int bytes)
{
	custom_string *result = (custom_string *) malloc((sizeof *result));
	result->length = 0;
	result->bytes = bytes;
	result->string = (char *) malloc((sizeof *(result->string))*bytes);

	return(result); 
}

void free_custom_string(custom_string *custom_string_struct)
{
	if(custom_string_struct != 0)
	{
		free(custom_string_struct->string);
		free(custom_string_struct);
	}
}

int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);
	for(int i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	custom_string program_name = {0};
	program_name.length = cstringlength(argv[0]);
	program_name.string = argv[0];

	custom_string* test_string = 0;
	test_string = init_empty_custom_string(10);
	free_custom_string(test_string);

	return(0);
}
