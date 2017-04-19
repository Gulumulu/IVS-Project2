#include "calculator.h"
#include <math.h>
#include <float.h>

int error_ret;
int error_div_zero;
const double DEPS = 1e-14;

double ADD(double x, double y){
    error_ret=0;
    return x+y;
}

double SUB(double x, double y){
    error_ret=0;
    return x-y;
}


double MUL(double x, double y){
    error_ret=0;
    return x*y;
}


double DIV(double x, double y){
    if(y==0){
        error_div_zero=1;
        error_ret=1;
        return 0;
    }
    else{
        error_div_zero=0;
        error_ret=0;
        return x/y;
    }
}


int FCT(unsigned long long int n){
    int pom=1;
    unsigned long long int tmp=n;
    while(tmp>0){
        pom=pom*tmp;
        tmp--;
        }
    error_ret=0;
    return pom;
}


double POW(double x, int n){
    double pom=x;
    for(int i=1; i<n; i++){
        pom=pom*x;
    }
    error_ret=0;
    return pom;
}


double SQRT(double x, int n) {
	double result = 1.0;
	double tmp = 1.0;
	if (n < 1 || (x < 0 && !(n & 1))) {
		error_ret = 1;
		return 0.0 / 0.0;
	}
	do {
		tmp = (x / pow(result, n - 1) - result) / n;
		result += tmp;
	} while (tmp >= DEPS * 10 || tmp <= -DEPS * 10);
	error_ret = 0;
	return result;
}


double ABSOL(double x){
    if(x<0){
        error_ret=0;
        return -x;
    }
    else {
        error_ret=0;
        return x;
    }
}









