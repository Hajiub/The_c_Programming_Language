/*
Exercise 5-16. Add the -d (``directory order'') option, which makes comparisons only on
    letters, numbers and blanks. Make sure it works in conjunction with -f.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#define MAXLINES 5000
int fold = 0;
int dir = 0;

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void freelines(char *lineptr[], int nlines);
void q_sort(void *lineptr[], int left, int right, int d,  int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

int main(int ac, char **av)
{
	/* the dec order flag works only with numeric!!! */
	int nlines;
	int numeric = 0;
	int reverse = 0;

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			if (av[i][0] == '-')
				switch (av[i][1])
				{
					case 'n':
						numeric = 1;
						break;
					case 'r':
						reverse = 1;
						break;
					case 'f':
						fold = 1;
						break;
                    case 'd':
                        dir = 1;
                        break;
					default:
						printf("Error: Invalid option");
						break;
				}
		}	
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		q_sort ((void**) lineptr, 0, nlines-1, reverse, (int (*) (void *, void *))(numeric ? numcmp : charcmp));
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
void q_sort(void *v[], int left, int right, int d,  int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	
	if (left >= right)
		return;

	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((!d && (*comp)(v[i], v[left]) < 0) || (d && (*comp)(v[i], v[left]) >=  0))
			swap (v, ++last, i);
	swap (v, left, last);
	q_sort (v, left, last-1, d, comp);
	q_sort (v, last+1, right, d, comp);
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
int charcmp(char *s1, char *s2)
{
    char a, b;
    do {
    if (dir)
    {
        while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0')
            s1++;
        while (!isalnum(*s2) && *s2 != ' ' && *s2 != '\0')
            s2++;
    }

    a = fold ? tolower(*s1) : *s1;
    s1++;
    b = fold ? tolower(*s2) : *s2;
    s2++;
    if (a == b && a == '\0')
        return 0;
    } while (a == b);
    return a - b;
}
void freelines(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		free(lineptr[i]);
}

