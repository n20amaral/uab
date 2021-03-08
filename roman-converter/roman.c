#include <string.h>
#include <stdlib.h>

#define ROMAN_SYMBOLS_COUNT 13

// globals
const char *romanSymbols[ROMAN_SYMBOLS_COUNT] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
const int romanValues[ROMAN_SYMBOLS_COUNT] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

// utils
int GetRomanSymbolIndex(char *roman, int index)
{
    char currentChar = roman[index];

    char *current = malloc(2 * sizeof(char));
    current[0] = currentChar;
    current[1] = '\0';

    char previousChar = index > 0 ? roman[index - 1] : '\n';
    char *previous = malloc(2 * sizeof(char));
    previous[0] = previousChar;
    previous[1] = '\0';

    int currentSymbolIndex = -1;
    int currentValue = 0;
    int previousSymbolIndex = -1;
    int previousValue = 0;

    for (int i = 0; i < ROMAN_SYMBOLS_COUNT; i++)
    {
        if (strcmp(romanSymbols[i], current) == 0)
        {
            currentSymbolIndex = i;
            currentValue = romanValues[i];
        }

        if (strcmp(romanSymbols[i], previous) == 0)
        {
            previousSymbolIndex = i;
            previousValue = romanValues[i];
        }
    }

    if (previous[0] == '\n')
    {
        free(previous);
        free(current);
        return currentSymbolIndex;
    }

    free(previous);
    free(current);

    if (currentSymbolIndex == -1 || previousSymbolIndex == -1)
    {
        return -1;
    }

    if (currentValue > previousValue)
    {
        char symbol[3];
        symbol[0] = roman[index - 1];
        symbol[1] = roman[index];
        symbol[2] = '\0';

        for (int i = 0; i < ROMAN_SYMBOLS_COUNT; i++)
        {
            if (strcmp(romanSymbols[i], symbol) == 0)
            {
                currentSymbolIndex = i;
                break;
            }
        }
    }

    return currentSymbolIndex;
}

// externals
int ValidateRoman(char *roman)
{
    int nextSymbolIndex = -1;
    int repeatCount = 1;

    for (int i = strlen(roman) - 1; i >= 0; i--)
    {
        int symbolIndex = GetRomanSymbolIndex(roman, i);

        // must have a matching symbol
        if (symbolIndex == -1)
        {
            return 1;
        }

        // only X, C or M symbols can preceed its lower adjacent (i.e. XIX)
        if (symbolIndex > 0 && symbolIndex % 4 != 0 && nextSymbolIndex + 1 == symbolIndex)
        {
            return 2;
        }

        // check wrong symbol ordering on subtract combinations
        if (strlen(romanSymbols[symbolIndex]) > 1)
        {
            switch (symbolIndex)
            {
            // IV an IX symbols cannot preceed other symbols (i.e. IVI)
            case 1:
            case 3:
                if (nextSymbolIndex != -1)
                {
                    return 2;
                }
                break;
            // XC and CM symbols cannot preceed its subtractors (i.e. XCX or CMC)
            case 7:
            case 11:
                if (nextSymbolIndex == symbolIndex - 3)
                {
                    return 2;
                }
                break;
            }

            i--;
        }

        // must keep descending symbol ordering
        if (nextSymbolIndex > symbolIndex)
        {
            return 2;
        }

        // check repetitions
        if (nextSymbolIndex == symbolIndex)
        {
            repeatCount++;
        }
        else
        {
            repeatCount = 1;
            nextSymbolIndex = symbolIndex;
        }

        // must not have more than 3 repetitions
        if (repeatCount > 3)
        {
            return 3;
        }

        // must not repeat V, L, D symbols
        if (repeatCount > 1 &&
            (symbolIndex == 2 || symbolIndex == 6 || symbolIndex == 10 || strlen(romanSymbols[symbolIndex]) > 1))
        {
            return 4;
        }
    }

    return 0;
}

int ConvertRomanToDecimal(char *roman)
{
    int validationStatus = ValidateRoman(roman);
    if (validationStatus > 0)
    {
        return 0 - validationStatus;
    }

    int value = 0;
    for (int i = strlen(roman) - 1; i >= 0; i--)
    {
        int symbolIndex = GetRomanSymbolIndex(roman, i);

        if (strlen(romanSymbols[symbolIndex]) > 1)
        {
            i--;
        }

        value += romanValues[symbolIndex];
    }

    return value;
}

const char *validationErrors[] = {
    "No errors found.",
    "Invalid symbol found.",
    "Invalid symbols ordering.",
    "Invalid sequence with length bigger than 3 symbols.",
    "Invalid sequence of V, L, D, IV, IX, XL, XC, CD or CM symbols."};