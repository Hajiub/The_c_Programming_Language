#include <stdio.h>
#include <stdbool.h>
#include <string.h>



bool isNoiseWord(char *s)
{
    bool found = false;
    char *list[] = {
        "a",
        "an",
        "and",
        "be",
        "but",
        "by",
        "he",
        "I",
        "is",
        "it",
        "off",
        "on",
        "she",
        "so",
        "the",
        "they",
        "you"
    };
    
    int right, left, mid;
    left = 0;
    int diff;
    right = sizeof(list) / sizeof(list[0]) - 1;

    while (left <= right)  // Fix: change the condition to ensure the loop terminates
    {
        mid = (left + right) / 2;
        if ((diff = strcmp(s, list[mid])) == 0)  // Fix: change word to s
        {
            found = true;
            break;
        }
        else if (diff > 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return found;
}

int main(void)
{
    char word[] = "The";
    char w[] = "the";
    printf("%i\n", i_strcmp(word, w));
    return 0;
}
