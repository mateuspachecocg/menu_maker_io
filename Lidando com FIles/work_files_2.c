#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale
#define false 0
#define true 1
struct emp
{
    char name[10];
    int age;
};

int main()
{
    struct emp e;
    FILE *p, *q;
    
    p = fopen("two.txt", "a");
    q = fopen("two.txt", "r");
    while(true){
        if (feof(q)){
            printf("Bye, Bye!");
        }
        fscanf(q, "%s %d", e.name, e.age);
        printf("%s %d\n", e.name, e.age);
    }

    
    printf("Enter Name and Age:");
    scanf("%s %d", e.name, &e.age);
    fprintf(p, "%s %d\n", e.name, e.age);
    fclose(p);
    fclose(q);
    
    return 0;
}