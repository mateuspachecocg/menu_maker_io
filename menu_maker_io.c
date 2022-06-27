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
  int tipo; // tipo = 1 (OpÃ§Ã£o 1), tipo = 2 (OpÃ§Ã£o 2, CONTÃ‰M FRANGO), tipo
            // = 3 (OpÃ§Ã£o Vegetariana)
};

struct guarnicao {
  char nome[20];
};

struct salada {
  char composicao[60];
  int qunatItens;
};

struct acompanhamento {
  char nome[20];
};

struct sobremesa {
  char nome[20];
};

struct cardapio {
  struct proteina opcao1[5];
  struct proteina opcao2[5];
  struct proteina vegetariana[5];
  struct guarnicao guarnicoes[5];
  struct acompanhamento acompanhamento[5];
  struct sobremesa sobremesa[2];
};

// NESTA PARTE VAO FICAR AS FUNCOES

void addProteina() {
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

void addSalada() { 
  struct salada sld;
  fptr = fopen("bd_salada.txt", "a");
  printf("COMPOSI€ÇO DA SALADA: ");
  scanf(" %[^\n]s", sld.composicao);
  printf("\nQUANTIDADE DE ITENS QUE COMPåEM A SALADA: ");
  scanf(" %d", &sld.qunatItens);
  fprintf(fptr, "\n%s\n%d", sld.composicao, sld.qunatItens);
  fclose(fptr);
}

void addGuarnicao(){
  struct guarnicao gnc;
  fptr = fopen("bd_gncs.txt", "a");
  printf("COMPOSI€ÇO DA GUARNI€ÇO: ", "a");
  scanf(" %[^\n]s", gnc.nome);
  fprintf(fptr, "\n%s", gnc.nome);
  fclose(fptr);
}

void addAcompanhamento(){
  struct acompanhamento acpmt;
  fptr = fopen("bd_acpmt.txt", "a");

}

void addSobremesa(){
  struct sobremesa sbms;
  fptr = fopen("bd_sbms.txt", "a");

}
// funcao para adicionar opcoes de cardapio: proteina, vegetariana,
// acompanhamento, sobremesa.
void addOpcao() {
  // Menu do addOpcao()
  printf("\n\n PRESSIONE: ");
  printf("\n 1.) INSERIR OP€ÇO DE PROTEÖNA.");
  printf("\n 2.) INSERIR OP€ÇO DE SALADA.");
  printf("\n 3.) INSERIR OP€ÇO DE GUARNI€ÇO.");
  printf("\n 4.) INSERIR OP€ÇO DE ACOMPANHAMENTO.");
  printf("\n 5.) INSERIR OP€ÇO DE SOBREMESA.");
  printf("\n 6.) VOLTAR.");
  printf("\nESCOLHA--> ");
  scanf("%d", &choice);
  switch (choice) {
  case 1: // Adcionar proteÃ­na
    addProteina();
    break;
  case 2: // Adiconar salada.
    addSalada();
    break;
  case 3: // Adiconar guarni‡Æo.
    addGuarnicao();
    break;
  case 4: // Adiconar acompanhamento.
    addAcompanhamento();
    break;
  case 5: // Adiconar sobremesa.
    addSobremesa();
    break;
  case 6: // Voltando ao menu anterior.
    printf("Voltando");
    break;
  default:
    printf("Op‡Æo Inv lida.");
  }
}

// funcao para editar alguma opÃ§Ã£o de CARDAPIO
void editOpcao() {}

// funcao para deletar alguma opÃ§Ã£o de CARDAPIO
void deleteOpcao() {}

// funcao para mostrar as opÃ§Ã£o de CARDAPIO
void displayOpcoesDisp() {}

// funcao para mostrar o cardapio
void showCardapio() {}

// funcao para fazer o cardÃ¡pio
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
    printf("\n 1.) INSERIR OP€åES.");
    printf("\n 2.) EDITAR OP€ÇO");
    printf("\n 3.) DELETAR OP€ÇO");
    printf("\n 4.) MOSTRAR OP€åES DISPONIVEIS");
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
    case 3: // DELETAR UMA OP€ÇO
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
      printf("VOCE NAO ESCOLHEU UMA OP€ÇO VµLIDA");
      break;
    }
  } while (choice != 7);
  printf("Thankyou for using this program");
}
