    /* 
    Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
                the length of arbitrary long input lines, and as much as possible of the text.
    */

    #include <stdio.h>

    #define MAXLINE 1000

    int getLine(char line[], int maxline);
    void copyString(char to[], const char from[]);

    int main() {
        int currentLength;
        int maxLength = 0;
        char currentLine[MAXLINE];
        char longestLine[MAXLINE];

        while ((currentLength = getLine(currentLine, MAXLINE)) > 0) {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                copyString(longestLine, currentLine);
            }
        }

        if (maxLength > 0) {
            printf("Longest line length: %i\n", maxLength);
            printf("Longest line:\n%s", longestLine);
        }

        return 0;
    }

    int getLine(char s[], int maxline) {
        int currentChar, i;

        for (i = 0; i < maxline - 1 && (currentChar = getchar()) != EOF && currentChar != '\n'; i++) {
            s[i] = currentChar;
        }

        if (currentChar == '\n') {
            s[i] = currentChar;
            i++;
        }

        s[i] = '\0';
        return i;
    }

    void copyString(char to[], const char from[]) {
        while ((*to++ = *from++));
    }
