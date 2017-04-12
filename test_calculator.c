#include "test_calculator.h"
#include "calculator.h"
#include <math.h>

int count_ok=0;
int count_errors=0;

int main(void) {

    /*scitani*/
    /*test1*/
    TEST_EQUAL_FLOAT("ADD:1", 69.2357+78.21354, ADD(69.2357, 78.21354));
    TEST_EQUAL_INT("ADD:1_ret", 0, error_ret);

    /*test2*/
    TEST_EQUAL_FLOAT("ADD:2", 852.3+159.2, ADD(852.3, 159.2));
    TEST_EQUAL_INT("ADD:2_ret", 0, error_ret);

    /*test3*/
    TEST_EQUAL_FLOAT("ADD:3", 8965.0+7452.0, ADD(8965.0, 7452.0));
    TEST_EQUAL_INT("ADD:3_ret", 0, error_ret);


    /*odcitani*/
    /*test4*/
    TEST_EQUAL_FLOAT("SUB:4", 58.2315647-63.2486234, SUB(58.2315647, 63.2486234));
    TEST_EQUAL_INT("SUB:4_ret", 0, error_ret);

    /*test5*/
    TEST_EQUAL_FLOAT("SUB:5", 895.23-175.37, SUB(895.23, 175.37));
    TEST_EQUAL_INT("SUB:5_ret", 0, error_ret);

    /*test6*/
    TEST_EQUAL_FLOAT("SUB:6", 19.0-48.0, SUB(19.0, 48.0));
    TEST_EQUAL_INT("SUB:6_ret", 0, error_ret);


    /*nasobeni*/
    /*test7*/
    TEST_EQUAL_FLOAT("MUL:7", 69.0*5.0, MUL(69.0, 5.0));
    TEST_EQUAL_INT("MUL:7_ret", 0, error_ret);

    /*test8*/
    TEST_EQUAL_FLOAT("MUL:8", 35.27*56*71, MUL(35.27, 56*71));
    TEST_EQUAL_INT("MUL:8_ret", 0, error_ret);

    /*test9*/
    TEST_EQUAL_FLOAT("MUL:9", 159.35764*752.3482, MUL(159.35764, 752.3482));
    TEST_EQUAL_INT("MUL:9_ret", 0, error_ret);


    /*deleni*/
    /*test10*/
    TEST_EQUAL_FLOAT("DIV:10", 78.0/24.0, DIV(78.0, 24.0));
    TEST_EQUAL_INT("DIV:10_ret", 0, error_ret);

    /*test11*/
    TEST_EQUAL_FLOAT("DIV:11", 845.23416/15.2486, DIV(845.23416, 15.2486));
    TEST_EQUAL_INT("DIV:11_ret", 0, error_ret);

    /*test12*/
    TEST_EQUAL_FLOAT("DIV:12", 5396.48/456.2, DIV(5396.48, 456.2));
    TEST_EQUAL_INT("DIV:12_ret", 0, error_ret);


    /*faktorial*/
    /*test13*/
    TEST_EQUAL_FLOAT("FCT:13", 2.0, FCT(2.0));
    TEST_EQUAL_INT("FCT:13_ret", 0, error_ret);

    /*test14*/
    TEST_EQUAL_FLOAT("FCT:14", 362880.0, FCT(9.0));
    TEST_EQUAL_INT("FCT:14_ret", 0, error_ret);

    /*test15*/
    TEST_EQUAL_FLOAT("FCT:15", NAN, FCT(6.178));
    TEST_EQUAL_INT("FCT:15_ret", 0, error_ret);


    /*mocnina*/
    /*test16*/
    TEST_EQUAL_FLOAT("POW:16", pow(12.635, 8), POW(12.635, 8));
    TEST_EQUAL_INT("POW:16_ret", 0, error_ret);

    /*test17*/
    TEST_EQUAL_FLOAT("POW:17", pow(51.7, 6), POW(51.7, 6));
    TEST_EQUAL_INT("POW:17_ret", 0, error_ret);

    /*test18*/
    TEST_EQUAL_FLOAT("POW:18", NAN, POW(85.47, 4.25));
    TEST_EQUAL_INT("POW:18_ret", 0, error_ret);


    /*odmocnina*/
    /*test19*/
    TEST_EQUAL_FLOAT("SQRT:19", 2.872429965, SQRT(23.7, 3));
    TEST_EQUAL_INT("SQRT:19_ret", 0, error_ret);

    /*test20*/
    TEST_EQUAL_FLOAT("SQRT:20", 4.0, SQRT(256.0, 4));
    TEST_EQUAL_INT("SQRT:20_ret", 0, error_ret);

    /*test21*/
    TEST_EQUAL_FLOAT("SQRT:21", 67.99374971, SQRT(4623.15, 2));
    TEST_EQUAL_INT("SQRT:21_ret", 0, error_ret);


    /*absolutni hodnota*/
    /*test22*/
    TEST_EQUAL_FLOAT("ABSOL:22", fabs(963.157), ABSOL(963.157));
    TEST_EQUAL_INT("ABSOL:22_ret", 0, error_ret);

    /*test23*/
    TEST_EQUAL_FLOAT("ABSOL:23", fabs(-452.0), ABSOL(-452.0));
    TEST_EQUAL_INT("ABSOL:23_ret", 0, error_ret);

    /*test24*/
    TEST_EQUAL_FLOAT("ABSOL:24", fabs(-21574.854231), ABSOL(-21574.854231));
    TEST_EQUAL_INT("ABSOL:24_ret", 0, error_ret);

    printf("___________________________________\n");

    printf("%d testu proslo, %d testu neproslo.\n", count_ok, count_errors);

    printf("___________________________________\n");
    return 0;
}









