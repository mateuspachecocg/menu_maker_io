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
  int tipo; // tipo = 1 (Opção 1), tipo = 2 (Opção 2, CONTÉM FRANGO), tipo
            // = 3 (Opção Vegetariana)
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
  int tipo; // tipo = 1 (Arroz), tipo = 2 (Feij�o)
};

struct sobremesa {
  char nome[20];
  int tipo; // tipo = 1 (Fruta); tipo = 2 (Doce);
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
  printf("COMPOSI��O DA SALADA: ");
  scanf(" %[^\n]s", sld.composicao);
  printf("\nQUANTIDADE DE ITENS QUE COMP�EM A SALADA: ");
  scanf(" %d", &sld.qunatItens);
  fprintf(fptr, "\n%s\n%d", sld.composicao, sld.qunatItens);
  fclose(fptr);
}

void addGuarnicao(){
  struct guarnicao gnc;
  fptr = fopen("bd_gncs.txt", "a");
  printf("COMPOSI��O DA GUARNI��O: ");
  scanf(" %[^\n]s", gnc.nome);
  fprintf(fptr, "\n%s", gnc.nome);
  fclose(fptr);
}

void addAcompanhamento(){
  struct acompanhamento acpmt;
  fptr = fopen("bd_acpmt.txt", "a");
  printf("COMPOSI��O DA GUARNI��O: ");
  scanf(" %[^\n]s", acpmt.nome);
  printf("TIPO DE GUARNI��O (1 - ARROZ; 2 - FEIJAO): ");
  scanf(" %d", &acpmt.tipo);
  fprintf(fptr,"\n%s\n%d", acpmt.nome, acpmt.tipo);
  fclose(fptr);
}

void addSobremesa(){
  struct sobremesa sbms;
  fptr = fopen("bd_sbms.txt", "a");
  printf("COMPOSI��O SOBREMESA: ");
  scanf(" %[^\n]s", sbms.nome);
  printf("TIPO DE SOBREMESA (1 - FRUTA; 2 - DOCE): ");
  scanf("%d", &sbms.tipo);
  fprintf(fptr,"\n%s\n%d", sbms.nome, sbms.tipo);
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
    addSalada();
    break;
  case 3: // Adiconar guarni��o.
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
