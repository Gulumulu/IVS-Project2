/**
*@file calculator.h
*@brief C-header file
*@date 22.4.2017
*@author Martin Minarik, Gabriel Quirschfeld, Tomas Svetlik, Jakub Zich
*/

#ifndef calculator_h
#define calculator_h

/**
*@brief error codes
*/
extern int error_ret;
extern int error_div_zero;

/**
*@brief Function for addition of two numbers of type double
*@param x first summand
*@param y second summand
*@return sum of x and y
*/
double ADD(double x, double y);

/**
*@brief Function for subtraction of two numbers of type double
*@param x minuend
*@param y subtrahend
*@return difference of x and y
*/
double SUB(double x, double y);

/**
*@brief Function for multiplication of two numbers of type double
*@param x first factor
*@param y second factor
*@return product of x and y
*/
double MUL(double x, double y);

/**
*@brief Function for division of two numbers of type double
*@param x dividend
*@param y divisor
*@warning y cannot equal zero
*@return fraction of x and y or 0 if error
*/
double DIV(double x, double y);

/**
*@brief Function for factorial of an integer
*@param n natural number
*@return factorial of n or NAN if error
*/
int FCT(int n);

/**
*@brief Function for exponentiation count
*@param x base
*@param n exponent
*@warning n must be positive number
*@return product of x^n or NAN if error
*/
double POW(double x, int n);

/**
*@brief Function for nth root
*@param x real number
*@param n index
*@warning n must be positive number
*@return nth root of number x or 0 if error
*/
double SQRT(double x, int n);

/**
*@brief Function for absolute value of a number of type double
*@param x real number
*@return absolute value of x
*/
double ABSOL(double x);

#endif
