#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (getLine(line, MAXLINE) > 0)	
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s", line);
				found++;
			}
	return found;
}

int getLine(char *line, int max)
{
	int i, c;
	for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;

	line[i]	 = '\0';
	return i;
}
