#include "calculator.h"
#include <math.h>
#include <float.h>

int error_ret;
int error_div_zero;
const double DEPS = 1e-14;

double ADD(double x, double y) {
    error_ret = 0;
    return x + y;
}

double SUB(double x, double y) {
    error_ret = 0;
    return x - y;
}

double MUL(double x, double y) {
    error_ret = 0;
    return x * y;
}

double DIV(double x, double y) {
    if (y == 0) {
        error_div_zero = 1;
        error_ret = 1;
        return 0;
    }
    else {
        error_div_zero = 0;
        error_ret = 0;
        return x / y;
    }
}


unsigned long long int FCT(int n) {
    unsigned long long int pom = 1;
    int tmp = n;
    while (tmp > 0) {
        pom *= tmp;
        tmp--;
        }
    error_ret = 0;
    return pom;
}


double POW_(double x, int n) {
	double pom = x;
	if (n == 0)
		return 1;
	for (int i = 1; i < n; i++) {
		pom *= x;
	}
	error_ret = 0;
	return pom;
}


double SQRT(double x, int n) {
	double result = 1.0;
	double tmp = 1.0;
	if (((n % 2) != 0) && (x != 0))
		return pow(x, 1.0/n);
	if ((n < 0) && (x == 0))
		return 0.0 / 0.0;
	if ((n < 0) && (x > 0))
		return pow(x, 1.0/n);
	if (n < 1 || (x < 0 && !(n & 1))) {
		error_ret = 1;
		return 0.0 / 0.0;
	}
	do {
		tmp = (x / POW_(result, n - 1) - result) / n;
		result += tmp;
	} while (tmp >= DEPS * 10 || tmp <= -DEPS * 10);
	error_ret = 0;
	return result;
}


double ABSOL(double x) {
    if (x < 0){
        error_ret = 0;
        return -x;
    }
    else {
        error_ret = 0;
        return x;
    }
}

