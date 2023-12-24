#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void freelines(char *lineptr[], int nlines);
void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int ac, char **av)
{
	int nlines;
	int numeric = 0;

	if (ac > 1 && strcmp(av[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		q_sort ((void**) lineptr, 0, nlines-1, (int (*) (void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		freelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("Input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000
int getLine(char *buffer, int lim)
{
	int i, c;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		buffer[i] = c;
	if (c == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	return i;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getLine(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = malloc(len)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* q_sort: sort v[left]...v[right] into increasing order */
void q_sort (void *v[], int left, int right, int (*comp) (void *, void*))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right)
		return;

	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap (v, ++last, i);
	swap (v, left, last);
	q_sort (v, left, last-1, comp);
	q_sort (v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
void freelines(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		free(lineptr[i]);
}


