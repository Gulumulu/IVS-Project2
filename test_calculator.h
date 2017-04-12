#ifndef test_calculator
#define test_calculator

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

const double EPS = 1e-14;

#define TEST_EQUAL_INT(name,value1,value2)                                                  \
	{                                                                                       \
        if (value1!=value2)                                                                 \
            {                                                                               \
            count_errors++;                                                                 \
            printf(ANSI_COLOR_RED   "Failed test - %s, line: %d!",name, __LINE__);          \
            printf(ANSI_COLOR_RESET "\n");                                                  \
            }                                                                               \
        else                                                                                \
            {                                                                               \
            count_ok++;                                                                     \
            printf(ANSI_COLOR_GREEN "Passed test - %s, line: %d!", name, __LINE__);         \
            printf(ANSI_COLOR_RESET "\n");                                                  \
            }                                                                               \
	}


#define TEST_EQUAL_FLOAT(name, value1, value2)                                              \
    {                                                                                       \
        if(fabs(value1-value2) >= EPS)                                                      \
            {                                                                               \
            count_errors++;                                                                 \
            printf(ANSI_COLOR_RED   "Failed test - %s, line: %d!",name, __LINE__);          \
            printf(ANSI_COLOR_RESET "\n");                                                  \
            }                                                                               \
        else                                                                                \
            {                                                                               \
            count_ok++;                                                                     \
            printf(ANSI_COLOR_GREEN "Passed test - %s, line: %d!", name, __LINE__);         \
            printf(ANSI_COLOR_RESET "\n");                                                  \
            }                                                                               \
    }                                                                                       \
#endif






