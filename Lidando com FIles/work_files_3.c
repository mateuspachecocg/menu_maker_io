#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#define false 0
#define true 1



int main()
{
    int num;
    FILE *fptr;

    fptr = fopen("three.txt", "a");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter num: ");
    scanf("%d", &num);

    fprintf(fptr, "\n%d", num);
    fclose(fptr);

    return 0;
}