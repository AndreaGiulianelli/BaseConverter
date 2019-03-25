#include <stdlib.h>
#include <stdio.h>
#include "baseConverter.h"

void main(int argc,char** argv)
{
    if(argc != 2)
    {
        printf("Impossibile eseguire.. Passare un numero valido di parametri\n");
        exit(1);
    }

    double n=atof(argv[1]);
    printf("Conversione %lf...\n",n);
    decimalToBin(n);
}