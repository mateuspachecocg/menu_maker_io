#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define false 0
#define true 1
// Global Variables
    FILE *fptr;

// Structs
struct person{
    char name[15];
    int age;
};

void insertPerson(void){
    
    fptr = fopen("five.txt", "a");
    struct person p;
    if(fptr == NULL){
        printf("File Open Error!");
        exit(1);
    }
    
    printf("Inserir nome da pessoa: ");
    scanf("%s", p.name);
    printf("Inserir idade da pessoa: ");
    scanf("%d", &p.age);

    if(fprintf(fptr, "\n%s %d", p.name, p.age) > 0){
        printf("Pessoa inserida com sucesso.");
    } else {
        printf("Erro na inserção. ");
    }
    
    fclose(fptr);
}

void displayPeople(void){
    fptr = fopen("five.txt", "r");
    struct person p;
    if(fptr == NULL){
        printf("File Open Error!");
        exit(1);
    }
    
    // Header
    printf("|             DADOS INSERIDOS              |");
    printf("\n|        NOME        |        IDADE        |");
    do{
        fscanf(fptr, "%s %d", p.name, &p.age );
        printf("\n %-20s %11d", p.name, p.age);
    }while(!feof(fptr));
    printf("\n");
    system("PAUSE");

}

int main(){
    
    int choice;

    // Menu Inicial do programa
    do{
        system("cls");
        printf("\n");
        printf("\t\t ++++++++++++++++++++++++++++++\n");
        printf("\t\t --- NOME E IDADE COM FILES ---\n");
        printf("\t\t ==============================");

        printf("\n\n Presione: ");
        printf("\n 1.) INSERIR NOME E IDADE.");
        printf("\n 2.) MOSTRAR TODAS AS PESSOAS.");
        printf("\n 3.) PARA SAIR DO PROGRAMA.");
        printf("\nESCOLHA--> ");
        scanf("%d", &choice);
        switch(choice){
            case 1: // Adiciona uma pessoa e idade ao arquivo.
                insertPerson();
                break;
            case 2: // Mostrar as pessoas inseridas.
                displayPeople();
                break;
            case 3:
                printf("Obrigado, por utilizar o programa.");
                break;
            default:
                printf("Opção Inválida.");
        }
    }while(choice != 3);

    return 0;
}