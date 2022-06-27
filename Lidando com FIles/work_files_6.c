#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#define false 0
#define true 1

int main()
{
    int num;
    char name[15];
    FILE *fptr;

    if((fptr = fopen("four.txt", "r")) == NULL){
        printf("Error! Opening File");
        exit(1);
    }
    
    do{
        fscanf(fptr, "%s %d", name, &num);
        printf("Name:  %s Age: %d years.\n",name, num);
    }while(!(feof(fptr)));

    fclose(fptr);
    return 0;
}