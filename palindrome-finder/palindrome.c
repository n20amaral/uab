#include <string.h>

int IsPalindrome(char *word)
{
    int length = strlen(word);

    if (length > 10 || length < 3)
    {
        return 1;
    }

    if (word[0] != word[length - 1])
    {
        return -1;
    }

    if (length == 3 || (length == 4 && word[1] == word[2]))
    {
        return 0;
    }

    char substring[length - 2];
    for (int i = 0; i < length - 2; i++)
    {
        substring[i] = word[i + 1];
    }
    substring[length - 1] = '\0';

    return IsPalindrome(substring);
}