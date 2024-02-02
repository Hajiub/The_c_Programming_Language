#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 100
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

int main(void)
{
   char names[][20] = {
        "Alice",
        "Bob",
        "Charlie",
        "David",
        "Eva",
        "Frank",
        "Grace",
        "Henry",
        "Ivy",
        "Jack",
        "Abraham",
        "Ali",
        "Hassan",
        "Asmea",
        "Fatima",
        "Zara",
        "Zahra",
        "Sarah",
        "Farah",
    };
    size_t size = sizeof(names) / sizeof(names[0]);
    for (size_t i = 0; i < size; i++)
        install(names[i], "Hello");

    displayTable();
    for (size_t i = 0; i < size; i++)
        undef(names[i]);

    displayTable();
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
        // Entry is at the beginning of the list
        hashtab[hashval] = current->next;
    }
    else
    {
        // Entry is in the middle or end of the list
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
