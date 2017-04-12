#ifndef test_calculator_h
#define test_calculator_h

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

const double EPS = 1e-14;

#define TEST_EQUAL_INT(name,value1,value2)                                                  \
	{                                                                                       \
        if (value1!=value2)                                                                 \
            {                                                                               \
            count_errors++;                                                                 \
            printf("Failed test - %s, line: %d!\n",name, __LINE__);                         \
            }                                                                               \
        else                                                                                \
            {                                                                               \
            count_ok++;                                                                     \
            printf("Passed test - %s, line: %d!\n", name, __LINE__);                        \
            }                                                                               \
	}

#define TEST_EQUAL_FLOAT(name, value1, value2)                                              \
    {                                                                                       \
        if(fabs(value1-value2) >= EPS)                                                      \
            {                                                                               \
            count_errors++;                                                                 \
            printf("Failed test - %s, line: %d!\n",name, __LINE__);                         \
            }                                                                               \
        else                                                                                \
            {                                                                               \
            count_ok++;                                                                     \
            printf("Passed test - %s, line: %d!\n", name, __LINE__);                        \
            }                                                                               \
    }                                                                                       \

#endif






