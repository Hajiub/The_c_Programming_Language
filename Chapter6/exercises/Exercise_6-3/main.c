#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLINE 8192

struct linenumber {
    int line;
    struct linenumber *next;
};

struct tnode {
    char *word;
    struct linenumber *firstline;
    struct tnode *left, *right;
};

char *tokenise(char **, char *);
char *GetLine(char *, int , FILE *);
int isNoiseWord(char *);
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
void treefree(struct tnode *);

int main(void)
{
    char buffer[MAXLINE] = {0};
    char *word = NULL;
    char *s = NULL;
    char *delims = " \t\n\r\a\f\v!\"%^&*()_=+{}[]\\|/,.<>:;#~?"; 
    int nline = 0;
    struct tnode *root = NULL;

    while ((GetLine(buffer, MAXLINE, stdin)) != NULL)
    {
        ++nline;
        s = buffer;
        while ((word = tokenise(&s, delims)) != NULL)
            if(!isNoiseWord(word))
                root = addtree(root, word, nline);
    }
    treeprint(root);
    treefree(root);
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

int isNoiseWord(char *s)
{ 
    int found = 0;
    int diff = 0;
    char *list[] = {
        "a",
        "an",
        "and",
        "be",
        "but",
        "by",
        "he",
        "I",
        "is",
        "it",
        "off",
        "on",
        "she",
        "so",
        "the",
        "they",
        "you"
    };

    int left, right, mid;
    left = 0;
    right = sizeof(list) / sizeof(list[0]);
    while (!found && left <= right)
    {

        mid = (left + right) / 2;
        if ((diff = i_strcmp(list[mid], s)) == 0)
        {
            found = 1;
        }
        else if (diff > 0)
        {
            right = mid - 1;
        }
        else 
            left = mid + 1;
    }
    return found;
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
struct linenumber *addline(int line)
{
    struct linenumber *temp = (struct linenumber *)malloc(sizeof(struct linenumber));
    if(temp)
    {
        temp->line = line;
        temp->next = NULL;
    }
}

struct tnode *addtree(struct tnode *p, char *word, int line)
{
    int cond;
    struct linenumber *n = NULL;
    if (p == NULL)
    {
        p = talloc();
        assert(p != NULL);
        p->word = mstrdup(word);
        p->firstline = addline(line);
        p->left = p->right = NULL;
    }
    else if ((cond = i_strcmp(p->word, word)) == 0)
    {
       n = addline(line);
       n->next = p->firstline;
       p->firstline = n;
    }
    else if (cond > 0)
        p->left = addtree(p->left, word, line);
    else
        p->right = addtree(p->right, word, line);
    return p;
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

void listprint(struct linenumber *list)
{
    if(list != NULL)
    {
        listprint(list->next);
        printf("%i ", list->line);
    }
}

void treeprint(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint(p->left);
        printf("Word: %s\n", p->word);
        printf("\tLine Numbers: ");
        listprint(p->firstline);
        putchar('\n');
        treeprint(p->right);
    }
}

void listfree(struct linenumber *list)
{
    if(list != NULL) 
    {
        listfree(list->next);
        free(list);
    }
}

void treefree(struct tnode *p)
{
    if (p != NULL)
    {
        treefree(p->left);
        free(p->word); 
        listfree(p->firstline);
        free(p);
        treefree(p->right);
    }
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
