#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define true 1
#define false 0
// Global variables
FILE *fptr;
int choice;
// Definindo structs
struct proteina {
  char nome[20];
  int porcao;
  int tipo; // tipo = 1 (Opção 1), tipo = 2 (Opção 2, CONTÉM FRANGO), tipo = 3 (Opção
            // Vegetariana)
};

struct gnc {
  char guarnicoes[20];
};

struct acpnmt {
  char acompanhamento[20];
};

struct sbms {
  char sobremesa[20];
};

struct cardapio {
  struct proteina opcao1[5];
  struct proteina opcao2[5];
  struct proteina vegetariana[5];
  struct gnc guarnicoes[5];
  struct acpnmt acompanhamento[5];
  struct sbms sobremesa[2];
};

// NESTA PARTE VAO FICAR AS FUNCOES

void addProteina(){
  struct proteina ptn;
    fptr = fopen("bd_opcoes.txt", "a");
    printf("NOME DA PROTEINA: ");
    scanf(" %[^\n]s", ptn.nome);
    printf("\nQUANTIDADE EM GRAMAS SERVIDA: ");
    scanf("%d", &ptn.porcao);
    printf("\nTIPO DE PROTEINA: ");
    scanf("%d", &ptn.tipo);
    fprintf(fptr, "\n%s\n%d\n%d", ptn.nome, ptn.porcao, ptn.tipo);
    fclose(fptr);
}
// funcao para adicionar opcoes de cardapio: proteina, vegetariana,
// acompanhamento, sobremesa.
void addOpcao() {
  // Menu do addOpcao()
  printf("\n\n PRESSIONE: ");
  printf("\n 1.) INSERIR OP��O DE PROTE�NA.");
  printf("\n 2.) INSERIR OP��O DE SALADA.");
  printf("\n 3.) INSERIR OP��O DE GUARNI��O.");
  printf("\n 4.) INSERIR OP��O DE ACOMPANHAMENTO.");
  printf("\n 5.) INSERIR OP��O DE SOBREMESA.");
  printf("\n 6.) VOLTAR.");
  printf("\nESCOLHA--> ");
  scanf("%d", &choice);
  switch (choice) {
  case 1: // Adcionar proteína
    addProteina();
    break;
  case 2: // Adiconar salada.
    // c�digo aqui.
    break;
  case 3: // Adiconar guarni��o.
    // c�digo aqui.
    break;
  case 4: // Adiconar acompanhamento.
    // c�digo aqui.
    break;
  case 5: // Adiconar sobremesa.
    // c�digo aqui.
    break;
  case 6: // Voltando ao menu anterior.
    printf("Voltando");
    break;
  default:
    printf("Op��o Inv�lida.");
  }
}

// funcao para editar alguma opção de CARDAPIO
void editOpcao() {}

// funcao para deletar alguma opção de CARDAPIO
void deleteOpcao() {}

// funcao para mostrar as opção de CARDAPIO
void displayOpcoesDisp() {}

// funcao para mostrar o cardapio
void showCardapio() {}

// funcao para fazer o cardápio
void makeCardapio() {}

// Inicializacao do programa
int main(void) {
  // Definindo variaveis e constantes

  int i;
  struct cardapio cdpo;

  do {
    printf("\n");
    printf("\t\t\t  ================================\n");
    printf("\t\t\t          MENU PLANNER IO \n");
    printf("\t\t\t  ================================");

    printf("\n\nPRESSIONE:");
    printf("\n 1.) INSERIR OP��ES.");
    printf("\n 2.) EDITAR OP��O");
    printf("\n 3.) DELETAR OP��O");
    printf("\n 4.) MOSTRAR OP��ES DISPONIVEIS");
    printf("\n 5.) MOSTRAR CARDAPIO");
    printf("\n 6.) GERAR UM CARDAPIO");
    printf("\n 7.) SAIR DO PROGRAMA.");
    printf("\nESCOLHA--> ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: // ADICIONA UMA OPCAO DO CARDAPIO
      addOpcao();
      break;
    case 2: // EDITA UMA OPCAO DO CARDAPIO
      editOpcao();
      break;
    case 3: // DELETAR UMA OP��O
      deleteOpcao();
      break;
    case 4: // MOSTRAR OPCOES DISPONIVEIS
      displayOpcoesDisp();
      break;
    case 5: // MOSTRAR O CARDAPIO DA SEMANA
      showCardapio();
      break;
    case 6: // CRIAR O CARDAPIO.
      makeCardapio();
      break;
    case 7: // SAIR DO SWITCH CASE
      exit(1);
      break;
    default:
      printf("VOCE NAO ESCOLHEU UMA OP��O V�LIDA");
      break;
    }
  } while (choice != 7);
  printf("Thankyou for using this program");
}
