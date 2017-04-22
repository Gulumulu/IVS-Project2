#ifndef test_calculator_h
#define test_calculator_h

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"


const double EPS = 1e-14;

#define TEST_EQUAL_INT(name,value1,value2)                                                  \
	{                                                                                       \
        if (value1!=value2)                                                                 \
            {                                                                               \
            count_errors++;                                                                 \
            printf(RED  "Failed test - %s, line: %d!",name, __LINE__);                      \
            printf(RESET    "\n");                                                          \
            }                                                                               \
        else                                                                                \
            {                                                                               \
            count_ok++;                                                                     \
            printf(GREEN    "Passed test - %s, line: %d!", name, __LINE__);                 \
            printf(RESET    "\n");                                                          \
            }                                                                               \
	}

#define TEST_EQUAL_FLOAT(name, value1, value2)                                              \
    {                                                                                       \
        if(fabs(value1-value2) >= EPS)                                                      \
            {                                                                               \
            count_errors++;                                                                 \
            printf(RED  "Failed test - %s, line: %d!",name, __LINE__);                      \
            printf(RESET    "\n");                                                          \
            }                                                                               \
        else                                                                                \
            {                                                                               \
            count_ok++;                                                                     \
            printf(GREEN    "Passed test - %s, line: %d!", name, __LINE__);                 \
            printf(RESET    "\n");                                                          \
            }                                                                               \
    }                                                                                       \

#endif






