/*
exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NL_THRESHOLD 10
#define MAX_LINES 1024
#define MAX_LENGTH 1024

void panic(char *message);
int getLine(char *buffer, int lim, FILE *inputStream);
void readLinesFromFile(char lines[MAX_LINES][MAX_LENGTH], int *nl, FILE *inputStream);
void printLines(char lines[MAX_LINES][MAX_LENGTH], int nl, int threshold);

int main(int argc, char **argv) 
{
    int threshold = NL_THRESHOLD;
    FILE *file = stdin;
    char *file_name = "stdin";
    int close = 0;

    if (argc >= 3) 
    {
        int f_flag_index, n_flag_index;
        f_flag_index = n_flag_index = -1;

        for (int i = 1; i < argc; i++) 
        {
            if (argv[i][0] == '-') 
            {
                switch (argv[i][1]) 
                {
                    case 'f':
                        f_flag_index = i;
                        break;
                    case 'n':
                        n_flag_index = i;
                        break;
                    default:
                        panic("Invalid flag");
                }
            }
        }

        if (n_flag_index > 0 && isdigit(*argv[n_flag_index + 1])) 
        {
            threshold = atoi(argv[n_flag_index + 1]);
        }
        if (f_flag_index > 0 && argv[f_flag_index + 1]) 
        {
            file_name = argv[f_flag_index + 1];
            file = fopen(file_name, "r");
            if (!file)
                panic("Error: opening file!");
	    close = 1;
        }
    }

    char lines[MAX_LINES][MAX_LENGTH];
    int nl = 0;
    readLinesFromFile(lines, &nl, file);
    if (close)
	    fclose(file);

    printf("Number of lines: %i\n", nl);
    int pos = (nl <= threshold) ? 0 : nl - threshold - 1;
    
    printf("\n=====================>%s<=====================\n", file_name);
    printLines(lines, nl, pos);
    printf("=================================================\n");
    return 0;
}

void panic(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int getLine(char *buffer, int lim, FILE *inputStream)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = fgetc(inputStream)) != EOF && c != '\n'; i++)
        buffer[i] = c;
    if (c == '\n')
        buffer[i++] = c;
    buffer[i] = '\0';
    if (i == lim - 1)
        panic("Input line is too long for the buffer!!!!!!");
    return i;
}

void readLinesFromFile(char lines[MAX_LINES][MAX_LENGTH], int *nl, FILE *inputStream) 
{
    int len;
    while ((len = getLine(lines[(*nl)++], MAX_LENGTH, inputStream)) > 0 && *nl < MAX_LINES);

}

void printLines(char lines[MAX_LINES][MAX_LENGTH], int nl, int threshold) 
{
    for (; threshold < nl; threshold++)
        printf("%s", lines[threshold]);
}
