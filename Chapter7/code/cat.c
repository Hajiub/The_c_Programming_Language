#include <stdio.h>

/* cat: concatenate files, version 1 */
int main(int ac, char **av)
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = av[0];
    if (ac == 1)
        filecopy(stdin, stdout);
    else
        while (--ac > 0)
            if ((fp = fopen(*++av, "r")) == NULL) {
                fprintf(stderr,"%s: %s: No such file or directory\n", prog,  *av);
                continue; 
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    return 0;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
