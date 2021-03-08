#include <stdio.h>
#include "roman.h"

int const INVALID_COUNT = 35;
char *invalidRomans[INVALID_COUNT] = {
    "MMMMM",
    "MMMM",
    "DD",
    "CCCC",
    "LL",
    "XXXX",
    "VV",
    "IIII",
    "CMCM",
    "CDCD",
    "XCXC",
    "XLXL",
    "IXIX",
    "IVIV",
    "IIMXCC",
    "VX",
    "DCM",
    "CMM",
    "IXIV",
    "MCMC",
    "XCX",
    "IVI",
    "LM",
    "LD",
    "LC",
    "T",
    "VITI",
    "IIII",
    "IIXX",
    "X 99",
    "XLXIV",
    "XLL",
    "LIXI",
    "MDXCXI",
    "LIXXI"};

int const VALID_COUNT = 62;
char *validRomans[VALID_COUNT] = {
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX",
    "X",
    "L",
    "C",
    "D",
    "M",
    "XXXI",
    "CXLVIII",
    "CCXCIV",
    "CCCXII",
    "CDXXI",
    "DXXVIII",
    "DCXXI",
    "DCCLXXXII",
    "DCCCLXX",
    "CMXLI",
    "MXLIII",
    "MCX",
    "MCCXXVI",
    "MCCCI",
    "MCDLXXXV",
    "MDIX",
    "MDCVII",
    "MDCCLIV",
    "MDCCCXXXII",
    "MCMXCIII",
    "MMLXXIV",
    "MMCLII",
    "MMCCXII",
    "MMCCCXLIII",
    "MMCDXCIX",
    "MMDLXXIV",
    "MMDCXLVI",
    "MMDCCXXIII",
    "MMDCCCXCII",
    "MMCMLXXV",
    "MMMLI",
    "MMMCLXXXV",
    "MMMCCL",
    "MMMCCCXIII",
    "MMMCDVIII",
    "MMMDI",
    "MMMDCX",
    "MMMDCCXLIII",
    "MMMDCCCXLIV",
    "MMMDCCCLXXXVIII",
    "MMMCMXL",
    "MMMCMXCIX",
    "CDIV",
    "XLIV",
    "MI",
    "LIX",
    "MMMCMXCIX",
    "MCMLXXIX"};

int validDecimals[VALID_COUNT] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    50,
    100,
    500,
    1000,
    31,
    148,
    294,
    312,
    421,
    528,
    621,
    782,
    870,
    941,
    1043,
    1110,
    1226,
    1301,
    1485,
    1509,
    1607,
    1754,
    1832,
    1993,
    2074,
    2152,
    2212,
    2343,
    2499,
    2574,
    2646,
    2723,
    2892,
    2975,
    3051,
    3185,
    3250,
    3313,
    3408,
    3501,
    3610,
    3743,
    3844,
    3888,
    3940,
    3999,
    404,
    44,
    1001,
    59,
    3999,
    1979};

int ValidateRomanTest()
{
    // char *validRomans[9] = {"I", "III", "IV", "VIII", "CDIV", "XLIV", "MI", "LIX", "MMMCMXCIX"};

    int fails = 0;
    for (int i = 0; i < VALID_COUNT; i++)
    {
        if (ValidateRoman(validRomans[i]) == 0)
        {
            continue;
        }

        printf("  FAILED: %s\n", validRomans[i]);
        fails++;
    }

    for (int i = 0; i < INVALID_COUNT; i++)
    {
        if (ValidateRoman(invalidRomans[i]) > 0)
        {
            continue;
        }

        printf("  FAILED: %s\n", invalidRomans[i]);
        fails++;
    }

    return fails;
}

int ConvertToRomanToDecimalTest()
{
    int fails = 0;

    for (int i = 0; i < VALID_COUNT; i++)
    {
        int decimal = ConvertRomanToDecimal(validRomans[i]);
        if (decimal != validDecimals[i])
        {
            printf("  FAILED: %s\n", validRomans[i]);
            fails++;
        }
    }

    return fails;
}

int main(int argc, char const *argv[])
{
    printf("TESTING: TestValidateRoman\n");
    int validateRomanTestResult = ValidateRomanTest();
    printf("TEST RESULT: %s\n", validateRomanTestResult == 0 ? "PASSED" : "FAILED");

    printf("TESTING: TestConvertRomanToDecimal\n");
    int convertRomanToDecimalTestResult = ConvertToRomanToDecimalTest();
    printf("TEST RESULT: %s\n", convertRomanToDecimalTestResult == 0 ? "PASSED" : "FAILED");
    return 0;
}
