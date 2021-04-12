#include <stdio.h>
#include "palindrome.h"

int main(int argc, char const *argv[])
{
    FILE *fp;
    char buffer[255];
    int counter = 0;
    fp = fopen("file.txt", "r");

    while (fscanf(fp, "%s", buffer) > 0)
    {
        if (IsPalindrome(buffer) == 0)
        {
            printf("%s ", buffer);
            counter++;
        }
    }

    fclose(fp);

    printf("\n %d palindromes found.\n", counter);

    return 0;
}
