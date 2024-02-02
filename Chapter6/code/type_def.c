#include <stdio.h>
#include <stdlib.h>

typedef char *String;
typedef struct tnode *Treeptr;

typedef struct tnode {
   String word; 
   int count;
   struct tnode *left, *right;
} Treenode;

Treeptr talloc(void)
{
    return (Treeptr) malloc(sizeof(Treenode));
}

int main(void)
{
    return 0;
}
