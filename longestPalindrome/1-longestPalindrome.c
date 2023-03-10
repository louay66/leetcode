#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *longestPalindrome(char *s)
{
	int len = strlen(s);
	int i, j, max_len, start, lock;
	max_len = start = 0;
	lock = 0;

	if (len == 1)
	{
		return s;
	}

	for (i = 0; i < len; i++)
	{
		if (s[i] == s[i + 1] && lock == 0 && max_len < 2)
		{
			max_len = 2;
			start = i;
			lock = 1;
		}

		j = 1;
		while (i - j >= 0 && i + j < len && s[i - j] == s[i + j])
		{
			if (2 * j + 1 > max_len)
			{
				max_len = 2 * j + 1;
				start = i - j;
			}

			j++;
		}
		if (i < len - 1 && s[i] == s[i + 1])
		{
			j = 1;
			while (i - j >= 0 && i + j + 1 < len && s[i - j] == s[i + j + 1])
			{
				if (2 * j + 2 > max_len)
				{
					max_len = 2 * j + 2;
					start = i - j;
				}

				j++;
			}
		}
	}

	if (max_len == 0)
	{
		max_len = 1;
	}

	char *result = malloc((max_len + 1) * sizeof(char)); // Allocate enough memory for the result
	strncpy(result, s + start, max_len);					  // Copy the palindrome substring to the

	result[max_len] = '\0'; // Add the null terminator to the result

	return result;
}
