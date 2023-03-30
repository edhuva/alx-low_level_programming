#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to be capitalized.
 *
 * Return: A pointer to the changed string.
 */
char *cap_string(char *str)
{
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] = str[0] - 32;
		}

		if (str[index] == ' ' || str[index] == '\t' ||
		    str[index] == '\n' || str[index] == ',' ||
		    str[index] == ';' || str[index] == '.' ||
		    str[index] == '!' || str[index] == '?' ||
		    str[index] == '"' || str[index] == '(' ||
		    str[index] == ')' || str[index] == '{' ||
		    str[index] == '}' || str[index] == '-')
		{
			if (str[index + 1] >= 97 && str[index + 1] <= 122)
			{
				str[index + 1] = str[index + 1] - 32;
			}
		}
		index++;
	}
	return (str);
}
