#include <stdio.h>

#define NSYM 100

typedef struct {
    char *name;
    int flags;
    int utype;
    union {
        int ival;
        float fval;
        char *sval;
    } u;
} symtab[NSYM];

int main(void)
{
    return 0;
}
