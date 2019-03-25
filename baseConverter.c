#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "baseConverter.h"

#define INITIAL_DIM 8

char* decimalToBin(double n)
{
    double resto = n;
    int dim = INITIAL_DIM;
    char* result = (char*) calloc(dim,1);
    int index=0;
    int precExp=0;
    int expo;
    while(resto!=0){
        if(resto > 1)
        {
            expo=(int) floor(log10(resto)/log10(2));
        }
        else
        {
            int i=-1;
            while(pow(2,i)>resto)
                i--;
            expo = i;
            result[index]='.';
            index++;
        }
        
        printf("\n%lf --> %d",resto,expo);
        resto -= pow(2,expo);
        printf("\n%lf",resto);
       
        if(expo<0)
        {
            index += abs(expo)-1;
        }else
        {
            if(abs(precExp) < abs(expo))
            {
                index = 0;
            }
            else
            {
            
                index += abs(precExp - expo-1);
            }
        }
        precExp = expo;
         if(index > dim){
            result = (char*) realloc(result,dim*2);
            dim*=2;
        }
        printf("\nIndex: %d",index);
        result[index] = '1';
        index++;
    }

    printf("\n");
    

    if(result[dim-1]!='1')
    {
        result = (char*) realloc(result,dim+1);
        dim+=1;
    }
    if(expo>0)
        result[index]='.';
    for(int i=0;i<dim;i++)
    {
        if(result[i]!='1')
        {
            printf("0");
        }
        printf("%c",result[i]);
    }

    return result;
}