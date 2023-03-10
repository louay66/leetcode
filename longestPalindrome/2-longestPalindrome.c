#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *longestPalindrome(char *s) {
	int len = strlen(s);
	int start = 0, max_len = 0;

	for (int i = 0; i < len; i++) {
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		int len = len1 > len2 ? len1 : len2;

		if (len > max_len) {
			max_len = len;
			start = i - (len - 1) / 2;
		}
	}

	char *result = malloc((max_len + 1) * sizeof(char));
	strncpy(result, s + start, max_len);
	result[max_len] = '\0';

	return result;
}

int expandAroundCenter(char *s, int left, int right) {
	int len = strlen(s);

	while (left >= 0 && right < len && s[left] == s[right]) {
		left--;
		right++;
	}

	return right - left - 1;
}
