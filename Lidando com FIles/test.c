#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#define false 0
#define true 1


int main()
{   
    char name[] = "Mateus";
    int age = 22;
    printf("|             DADOS INSERIDOS              |");
    printf("\n|        NOME        |        IDADE        |");
    
    printf("\n %-20s %11d", name, age);
    
    return 0;
}