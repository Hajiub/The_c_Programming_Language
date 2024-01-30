#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLINE 8192

struct tnode {
    char *word;
    int count;
    struct tnode *left, *right;
};

struct tnode *addtree(struct tnode *, char *, int *);
void treeprint(struct tnode *);
void treefree(struct tnode *);
void populateNodesArray(struct tnode *, struct tnode **, int *);
void quickSort(struct tnode **, int , int);
void DisplayArray(struct tnode **, int);

char *tokenise(char **, char *);
char *GetLine(char *, int , FILE *);

int main(void)
{
    char buffer[MAXLINE] = {0};
    char *word = NULL;
    char *s = NULL;
    char *delims = " \t\n\r\a\f\v!\"%^&*()_=+{}[]\\|/,.<>:;#~?"; 
    struct tnode *root = NULL;
    int treecount = 0;
    while ((GetLine(buffer, MAXLINE, stdin)) != NULL)
    {
        s = buffer;
        while ((word = tokenise(&s, delims)) != NULL)
            root = addtree(root, word, &treecount);
    }

    struct tnode **array;
    array = (struct tnode **)malloc(sizeof(struct tnode) * treecount);
    assert(array != NULL);
    int index = 0;
    populateNodesArray(root, array, &index);
    quickSort(array, 0, index - 1);
    DisplayArray(array, index);
    treefree(root);
    free(array);
    return 0;
}

int i_strcmp(const char *s1, const char *s2)
{
    int diff = 0;
    char c1 = 0;
    char c2 = 0;

    while (diff == 0 && *s1 != '\0' && *s2 != '\0')
    {
        c1 = tolower(*s1);
        c2 = tolower(*s2);

        if (c1 > c2)
            diff = 1;

        else if (c1 < c2)
            diff = -1; 

        s1++;
        s2++; 
    }
    if (diff == 0 && *s1 != *s2)
    {
        if (*s1 == '\0')
            diff = -1;

        else 
            diff = 1;
    }
    return diff;
}

char *mstrdup(char *s)
{
    char *temp = NULL;
    if (s != NULL)
    {
        temp = (char *)malloc(strlen(s) + 1);

        if(temp)
            strcpy(temp, s);
    }
    return temp;
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *word, int *n)
{
    int diff;
    if(p == NULL)
    {
        p = talloc();
        p->word = mstrdup(word);
        p->count = 1;
        (*(int *)n)++;
    }

    else if((diff = strcmp(p->word, word)) == 0)
    {
        p->count++;
    }
    
    else if (diff < 0)
    {
        p->right = addtree(p->right, word, n);
    }

    else
    {
        p->left = addtree(p->left, word, n);
    }
    return p;
}

void treeprint(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint(p->left);
        printf("%i:%s\n", p->count, p->word);
        treeprint(p->right);
    }
}
void treefree(struct tnode *p)
{
    if(p != NULL)
    {
        treefree(p->left);
        free(p->word);
        free(p);
        treefree(p->right);
    }
}

void populateNodesArray(struct tnode *p, struct tnode **array, int *index)
{
    if(p != NULL)
    {
        populateNodesArray(p->left, array, index);
        array[(*index)++] = p;
        populateNodesArray(p->right, array, index);
    }
}

void swap(struct tnode **arr, int a, int b)
{
    struct tnode *temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partion(struct tnode **array, int left, int right)
{
    int piv = array[right]->count;
    int i, j;
    for (i = left - 1, j = left; j < right; j++)
        if(array[j]->count >= piv) 
            swap(array, ++i, j);
    swap(array, ++i, right);
    return i;
}

void quickSort(struct tnode **array, int left , int right)
{
    if (left >= right)
        return;
    int pr = partion(array, left, right);
    quickSort(array, left, pr - 1);
    quickSort(array, pr + 1, right);
}
char *char_in_string(char *s, int c)
{
    char *p = NULL;
    if (s != NULL)
    {
        if (c != '\0')
        {
            while (*s != '\0' && *s != c)
                ++s;
            if (*s == c)
                p = s;
        }
    }
    return p;
}

void DisplayArray(struct tnode **array, int s)
{
    printf("Count : Word\n");
    for (int i = 0; i < s; i++)
        printf("%i : %s\n", array[i]->count, array[i]->word);
}

char *tokenise(char **s, char *delims)
{
  char *p = NULL;
  char *q = NULL;

  if(s != NULL && *s != '\0' && delims != NULL)
  {

    while(NULL != char_in_string(delims, **s))
    {
      ++*s;
    }
    if(**s != '\0')
    {
      q = *s + 1;
      p = *s;
      while(*q != '\0' && NULL == char_in_string(delims, *q))
      {
        ++q;
      }

      *s = q + (*q != '\0');
      *q = '\0';
    }
  }

  return p;
}

char *GetLine(char *s, int n, FILE *fp)
{
    int c = 0;
    char *p = s;
    while (--n > 0 && (c = getc(fp)) != EOF)
        if ((*p++ = c) == '\n')
            break;
    *p = '\0';
    if (c == EOF && p == s)
        p = NULL;
    else
        p = s;
    return p;
}
