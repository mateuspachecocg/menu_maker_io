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

    fptr = fopen("four.txt", "a");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter with name and age: ");
    scanf("%s %d", name, &num);

    fprintf(fptr, "\n%s %d", name, num);
    fclose(fptr);

    return 0;
}