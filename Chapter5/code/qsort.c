/*
 * read all the lines of input
 * sort them
 * print them in order
*/
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to sorted */ 

char *lineptr[MAXLINES]; /* pointer to text linex */ 

int readlines (char *lineptr[], int nlines);
void writelines (char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main(void)
{
	int nlines; /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }

}

#define MAXLEN 1000 /* max length of any input line */
int getLine(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0'; /* remove newline */
	    strcpy(p, line);
	    lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* wrtielines: write ouput lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap (char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getLine(char *s, int max)
{
    int c;
    char *p = s;
    while ((c = getchar())!= EOF && c!= '\n' && (int)(p - s) < max - 1)
    {
        *p++ = c;
    }
    if(c == '\n')
        *p++ = '\n';
    *p = '\0';

    return (int)(p - s);
}



#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) 
{
    if (allocbuf + ALLOCSIZE - allocp >= n) 
    {
        allocp += n;
        return allocp - n;
    } 
    else 
    {
        return NULL;
    }
}
