#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

float calculateSO(float *x, unsigned int N){
    float aver, aver2, sum = 0.0, sum2 = 0.0, pom;

    for (int i = 0; i <= N; i++){
      sum += x[i];
    }
    aver = sum/N;
    aver2 = POW(aver, 2);
    for (int j = 0; j <= N; j++){
      sum2 += POW(x[j], 2);
    }
    sum2 -= N * aver2;
    pom = sum2/(N - 1);

    return SQRT(pom, 2);
}

int main()
{
    int i;
    unsigned n;
    float a[1001];

    printf("Zadaj pocet cisel (1 - 1 000): ");
    if (!(scanf("%u", &n))){
      fprintf(stderr, "Zly vstup\n");
      return 1;
    }
    if (!(n <= 1000) && (n > 0)){
      fprintf(stderr, "Zly pocet cisel\n");
      return 1;
    }

    printf("Zadaj cisla:\n");
    for(i=0; i < n; ++i){
      if (!(scanf("%f", &a[i]))){
        fprintf(stderr, "Zly vstup\n");
        return 1;
      }
    }

    printf("Smerodajna odchylka = %.4f\n", calculateSO(a, n));

    return 0;
}
