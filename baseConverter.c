#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define INITIAL_DIM 8

char* decimalToBin(double n)
{
    double resto = n;
    int dim = INITIAL_DIM;
    char* result = (char*) calloc(dim);
    do{
        int exp=(int) floor(log10(n)/log10(2));
        resto -= pow(2,exp);
        if(exp > dim){
            result = (char*) realloc(result,dim*2);
            dim*=2;
        }
        result[dim - (dim - INITIAL_DIM + exp)] = 1;
    }while(resto!=0)
}