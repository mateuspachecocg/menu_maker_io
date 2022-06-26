#include <stdio.h>
#include <stdlib.h>

// Definindo structs
struct proteina{
  char nome[20];
};

/*struct op2{
  char opcao2[20];
}; */

struct gnc{
  char guarnicoes[20];
};

struct acpnmt{
  char acompanhamento[20];
};

struct sbms{
  char sobremesa[20];
};

struct cardapio{
  struct proteina opcao1[5];
  struct proteina opcao2[5];
  struct proteina vegetariana[5];
  struct gnc guarnicoes[5];
  struct acpnmt acompanhamento[5];
  struct sbms sobremesa[2];
};

// funcao cadastro de opcoes.

//funcao lerOpcoes()

// Inicializacao do programa
int main (void)
{
  //Definindo variaveis e constantes
  int i;



  struct cardapio cdpo;
  printf ("\n---------- Digite as 05 opcoes de proteina: ---------- \n\n\n");

  for(i = 0;i<5; i++){
    scanf (" %[^\n]s", cdpo.opcao1[i].nome);
    printf (" %s", cdpo.opcao1[i].nome);
  }

  printf(" \t\t\t\t *****  CARDAPIO *****\n");
   printf("------------------------------------------------------------------------------------\n");
   printf("ALMOÇO |   SEGUNDA   |     TERÇA     |     QUARTA     |     QUINTA     |    SEXTA     |\n");
   printf("------------------------------------------------------------------------------------\n");

}

