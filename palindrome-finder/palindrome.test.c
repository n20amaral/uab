#include <stdio.h>
#include "palindrome.h"

int const TEST_CASES_COUNT = 3;
char *palindromes[TEST_CASES_COUNT] = {"aca", "abba", "racecar"};
char *nonPalindromes[TEST_CASES_COUNT] = {"abc", "potato", "racerbikes"};
char *invalidInputs[TEST_CASES_COUNT] = {"a", "cc", "nolemonnomelon"};

int IsPalindromeTest()
{
    int fails = 0;

    for (int i = 0; i < TEST_CASES_COUNT; i++)
    {
        if (IsPalindrome(palindromes[i]) != 0)
        {
            printf("FAILED: %s\n", palindromes[i]);
            fails++;
        }

        if (IsPalindrome(nonPalindromes[i]) >= 0)
        {
            printf("FAILED: %s\n", nonPalindromes[i]);
            fails++;
        }

        if (IsPalindrome(invalidInputs[i]) <= 0)
        {
            printf("FAILED: %s\n", invalidInputs[i]);
            fails++;
        }
    }

    return fails;
}

int main(int argc, char const *argv[])
{
    printf("TESTING: IsPalindrome\n");
    int isPalindromeTestResult = IsPalindromeTest();
    printf("TEST RESULT: %s\n", isPalindromeTestResult == 0 ? "PASSED" : "FAILED");

    return 0;
}
