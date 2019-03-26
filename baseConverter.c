#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "baseConverter.h"

#define INITIAL_DIM 8

void decimalToBin(double n)
{
    double resto = n; //Resto della sottrazione con le potenze del 2
    int dim = INITIAL_DIM; //Dimensione dell'array di char
    char* result = (char*) calloc(dim,1); //Array dinamico di char che contiene il risultato
    int index=0; //Variabile che memorizza l'indice attuale 
    int precExp=0; //Esponente precedente
    int expo; //Esponente attuale

    while(resto!=0){ 
        //Finche non ho rappresentato completamente il numero, continuo a ciclare

        if(resto > 1)
        {
            //Se il resto è maggiore di 1 posso applicare il logaritmo per trovare il risultato
            expo=(int) floor(log10(resto)/log10(2));
        }
        else
        {
            //Se il resto è minore di 1 vado per prove finchè non trovo l'esponente giusto
            int i=-1;
            while(pow(2,i)>resto)
                i--;
            expo = i;
            //Non rappresento numeri con una precisione maggiore di 2^(-15)
            if(expo < -15)
            {
                break;
            }
        }
        
        //printf("\n%lf --> %d",resto,expo);
        resto -= pow(2,expo);
        //printf("\n%lf",resto);

        if(expo < 0 && precExp > 0)
        {
            //Se passo nella parte decimale del numero (quindi ho un cambio di segno nell'esponente) allora inserisco il punto
            index += abs(precExp)+1; //Calcolo la posizione del punto in base all'ultimo esponente
            result[index] = '.';
            precExp = 0; //Imposto a zero il nuovo esponente
        }

        //Se devo spostare l'indice perchè devo memorizzare un altro "1" allora mi calcolo la distanza tra i due esponenti
        if((precExp - expo) > 0)
        {
            index += abs(precExp - expo);
        }
        
        precExp = expo;
        //Se l'indice non è contenuto allora raddoppio il vettore
        if(index > dim){
            result = (char*) realloc(result,dim*2);
            dim*=2;
        }
        //printf("\nIndex: %d",index);
        //Inserisco "1" nella posizione corretta
        result[index] = '1';
    }

    printf("\n");
    
    //Se il numero non ci sta tutto raddoppio la dimensione
    if(result[dim-1]!='0' || expo > dim)
    {
        result = (char*) realloc(result,dim*2);
        dim*=2;
    }

    //Se esponente è maggiore di 0 allora avrò delle posizioni in piu nel vettore che verranno visualizzate.. Perciò devo inserire una virgola nella giusta posizione
    if(expo>0)
    {
        index += abs(expo)+ 1;
        result[index]='.';
    }

    //Visualizzo il vettore
    for(int i=0;i<dim;i++)
    {
        if(result[i]!='1' && result[i]!='.')
        {
            printf("0");
            continue;
        }
        printf("%c",result[i]);
    }
    printf("\n");
}