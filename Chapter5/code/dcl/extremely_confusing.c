#include <stdio.h>

char a() { return 'a';}
char b() {return 'b';} 
char c() {return 'c';}

char (*xarr[])() = {a, b, c};
char (*(*x())[])() {return &xarr;}
int main(void)
{
    printf("%c\n", ((*(x()))[0])());
    printf("%c\n", ((*(x()))[1])());
    printf("%c\n", ((*(x()))[2])());
    return 0;
}
