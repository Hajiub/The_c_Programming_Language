#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct tnode {      /* the tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void treefree(struct tnode *p);
int getword(char *, int);

int main(void)
{
    char word[MAXWORD];
    struct tnode *root;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0])) 
            root = addtree(root, word);
    treeprint(root);
    treefree(root);
    return 0;
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *word)
{ 
    int cond;
    if(!p)
    {
        p = talloc();
        p->word = strdup(word);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(word, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, word);
    else 
        p->right = addtree(p->right, word);

    return p;
}

/* treeprint: in-order print of tree */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d : %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
void treefree(struct tnode *p)
{
    if (p)
    {
        treefree(p->left);
        treefree(p->right);
        free(p->word);
        free(p);
    }
}
int getword(char *word, int lim)
{
   int c, getch(void);
   void ungetch(int);
   while (isspace(c = getch()));
   if (c != EOF)
       *word++ = c;
   if (!isalpha(c))
   {
       *word = '\0';
       return c;
   }

   for (; lim; word++)
       if(!isalnum(*word = getch()))
       {
           ungetch(*word);
           break;
       }
   *word = '\0'; 
   return word[0];
}

#define MAXBUFF 100
static char buffer[MAXBUFF];
static int bp = 0;

int getch()
{
    return (bp > 0) ? buffer[--bp] : getchar();
}

void ungetch(int c)
{
    if (bp < MAXBUFF)
        buffer[bp++] = c;
}
