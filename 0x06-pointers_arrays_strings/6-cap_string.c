#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to be capitalized.
 *
 * Return: A pointer to the changed string.
 */

char *cap_string(char *str)
{
	int s_count;

	s_count = 0;
	while (str[s_count] != '\0')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] = str[0] - 32;
		}

		if (str[s_count] == ' ' || str[s_count] == '\t' || str[s_count] == '\n'
		|| str[s_count] == ',' || str[s_count] == ';' || str[s_count] == '.'
		|| str[s_count] == '!' || str[s_count] == '?' || str[s_count] == '"'
		|| str[s_count] == '(' || str[s_count] == ')' || str[s_count] == '{'
		|| str[s_count] == '}')
		{
			if (str[s_count + 1] >= 97 && str[s_count + 1] <= 122)
			{
				str[s_count + 1] = str[s_count + 1] - 32;
			}
		}
		s_count++;
	}

	return (str);
}
