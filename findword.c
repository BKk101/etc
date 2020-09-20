#include <stdio.h>
#include <string.h>

int find_word(char * str, char * word)
{
	int cnt = 0;
	int i,j;

	while (*str) {
		for (i=0,j=0;str[i]!='\0' && str[i] == word[j];i++, j++);
		if (j == strlen(word)) cnt++;
		str++;
	}
	return cnt;
}

int main(void)
{
	char str[256];
	char word[16];
	int n;

	printf("Input sentence : ");
	gets(str);
	printf("Input word : ");
	scanf("%s", word);
	n = find_word(str,word);
	printf("There are<is> %d word in the sentence.", n);
	return 0;
}