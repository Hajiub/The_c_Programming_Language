#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 100
#define MAXLEN 1000
#define MAXWORD 100

struct nlist {
    char *name, *defn;    
    struct nlist *next;
};

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *);
char *mstrdup(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
void displayTable(void);
void freeTable(void);
int getLine(FILE *, char *, int);
char *tokenise(char **, char *);

int main(void)
{
    char line[MAXLEN];
    char *delims = " #";
    char *s, *word;
    char tokens[2][MAXWORD];
    while ((getLine(stdin, line, MAXLEN)) > 0)
    {
        if (strlen(line) == 1 && line[0] == 'q')
            break;
        else if(line[0] == '#')
        {
            s = line;
            int i = 0;
            while ((word = tokenise(&s, delims)))
            {
                if(strcmp(word, "define") == 0)
                    continue;
                else
                    strcpy(tokens[i++], word);
            }
            install(tokens[0], tokens[1]);
        }
    }

    displayTable();
    freeTable();
    return 0;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval += *s + 31 * hashval;
   return hashval % HASHSIZE;
}

char *mstrdup(char *s)
{
    char *temp = NULL;
    if (s != NULL)
    {
        temp = (char *)malloc(sizeof(strlen(s) + 1));
        if(temp != NULL) 
            strcpy(temp, s);
    }
    return temp;
}

struct nlist *lookup(char *s)
{
    struct nlist *np = NULL;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;

    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) ==  NULL) /* not found */
    {
        np = (struct nlist *) malloc(sizeof(struct nlist));
        if (np == NULL || (np->name = mstrdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *) np->defn);

    if ((np->defn = mstrdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *name)
{
    struct nlist *current = NULL;
    struct nlist *previous = NULL;
    unsigned hashval = hash(name);

    current = hashtab[hashval];

    while (current != NULL && strcmp(name, current->name) != 0)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Entry with name '%s' not found in the hash table.\n", name);
        return;
    }

    if (previous == NULL)
    {
        hashtab[hashval] = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current->name);
    free(current->defn);
    free(current);

    printf("Entry with name '%s' removed from the hash table.\n", name);
}

void displayList(struct nlist *np)
{
    struct nlist *temp = np;
    while (temp)
    {
        printf("%s : %s\n", temp->name, temp->defn);
        temp = temp->next;
    }
}

void displayTable(void)
{
    printf("Name : Defn\n");
    for (int i = 0; i < HASHSIZE; i++)
    {
        if (hashtab[i])
        {
            displayList(hashtab[i]);
        }
    }
}
void freeList(struct nlist *list)
{
    if(list)
    {
        freeList(list->next);
        free(list->name);
        free(list->defn);
        free(list);
    }
}
void freeTable(void)
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        if (hashtab[i])
        {
            freeList(hashtab[i]);
        }
    }
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

int getLine(FILE *input_stream, char *buffer, int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getc(input_stream)) != EOF && c != '\n'; i++) 
        buffer[i] = c;
   buffer[i] = '\0';
    return i;
}
