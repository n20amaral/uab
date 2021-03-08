#include <stdio.h>
#include "roman.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Arguments. Please run as: af0 <roman number>\n");
        return 1;
    }

    char *roman = argv[1];
    int decimal = ConvertRomanToDecimal(roman);

    if (decimal < 0)
    {
        printf("%s is invalid roman number. (%s)\n", roman, validationErrors[0 - decimal]);
        return 0;
    }

    printf("The roman %s is equal to %i decimal value\n", roman, decimal);

    return 0;
}
