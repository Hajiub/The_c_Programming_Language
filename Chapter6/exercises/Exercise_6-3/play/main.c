#include <stdio.h>
#include <ctype.h>

int i_strcmp(const char *s1, const char *s2)
{
    int diff = 0;
    char c1 = 0;
    char c2 = 0;

    while (diff == 0 && *s1 != '\0' && *s2 != '\0')
    {
        c1 = tolower(*s1);
        c2 = tolower(*s2);

        if (c1 > c2)
            diff = 1;

        else if (c1 < c2)
            diff = -1; 

        s1++;
        s2++; 
    }
    if (diff == 0 && *s1 != *s2)
    {
        if (*s1 == '\0')
            diff = -1;

        else 
            diff = 1;
    }
    return diff;
}

int isNoiseWord(char *s)
{ 
    int found = 0;
    int diff = 0;
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

    int left, right, mid;
    left = 0;
    right = sizeof(list) / sizeof(list[0]);
    while (!found && left <= right)
    {

        mid = (left + right) / 2;
        if ((diff = i_strcmp(list[mid], s)) == 0)
        {
            found = 1;
        }
        else if (diff > 0)
        {
            right = mid - 1;
        }
        else 
            left = mid + 1;
    }
    return found;
}


int main(void)
{
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
 
    size_t size = sizeof(list) / sizeof(list[0]);
    for (int i = 0 ; i < size; i++)
        printf("%s: %i\n", list[i], isNoiseWord(list[i]));
    return 0;
}
