#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#define false 0
#define true 1



int main()
{
    int num;
    FILE *fptr;

    if((fptr = fopen("three.txt", "r")) == NULL){
        printf("Error! Opening File");
        exit(1);
    }
    
    do{
        fscanf(fptr, "%d", &num);
        printf("Value of n = %d\n", num);
    }while(!(feof(fptr)));

    fclose(fptr);
    return 0;
}