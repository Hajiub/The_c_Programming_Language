#include <stdio.h>

/* strcpy: copy t to s; array subscript version */
void strcpy(char *from, char *to)
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}

/* strcpy: copy t to s; pointer version */
void strcyp_pv1(char *from, char *to)
{
    int i;
    i = 0;
    while ((*to = *from)!= '\0')
    {
        to++;
        from++;
    }
}
/* strcpy: copy t to s; pointer version 2 */
void strcpy_pv2(char *from, char *to)
{
    while((*to++ = *from++) != '\0');
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy_pv3(char *from, char *to)
{
    while(*to++ = *from++);
}