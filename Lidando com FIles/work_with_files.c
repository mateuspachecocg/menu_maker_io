#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //necessário para usar setlocale


int main()
{
    FILE *fp;
    char ch;
    setlocale(LC_ALL,"");

    fp = fopen("one.txt", "w");
    printf("Enter data...");
    while((ch = getchar())!= EOF){
        putc(ch, fp);
    }

    fclose(fp);
    fp = fopen("one.txt", "r");
    while((ch = getc(fp)!= EOF)){
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}