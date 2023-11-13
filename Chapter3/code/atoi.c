#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}


int main() {
    char str1[] = "10";
    char str2[] = "-456";
    char str3[] = " 789";

    int result1 = atoi(str1);
    int result2 = atoi(str2);
    int result3 = atoi(str3);

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    printf("Result 3: %d\n", result3);

    return 0;
}
