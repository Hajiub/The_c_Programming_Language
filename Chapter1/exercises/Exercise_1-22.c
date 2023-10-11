/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
               the last non-blank character that occurs before the n-th column of input. Make sure your
               program does something intelligent with very long lines, and if there are no blanks or tabs
               before the specified column.
*/
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 30
#define MAX_LINE_BUFFER 1024

int getLine(char *s, int max);
void fold(char *s, int len, int max_line_length);

int main() {
    char line[MAX_LINE_BUFFER];
    int len;

    while ((len = getLine(line, MAX_LINE_BUFFER)) > 0) {
        fold(line, len, MAX_LINE_LENGTH);
    }

    return 0;
}

int getLine(char *s, int max) {
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i++] = '\n';
    }

    s[i] = '\0';
    return i;
}

void fold(char *s, int len, int max_line_length) {
    int i, j;
    i = j = 0;

    while (s[i]) {
        if (j < max_line_length) {
            putchar(s[i]);
            j++;
        } else {
            if (isspace(s[i])) {
                putchar('\n');
            } 
            
            else {
                putchar('-');
                putchar('\n');
                putchar(s[i]);
            }
            j = 0;
        }
        i++;
    }
}

