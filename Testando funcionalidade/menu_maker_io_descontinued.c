#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0
// Global variables
FILE *fptr;
int choice;
// Definindo structs
struct proteina {
  char nome[20];
  int porcao;
  int tipo; // tipo = 1 (Op��o 1), tipo = 2 (Op��o 2, CONT�M FRANGO), tipo
            // = 3 (Op��o Vegetariana)
};

struct guarnicao {
  char nome[20];
};

struct salada {
  char composicao[60];
  int qunatItens;
};

struct acompanhamento {
  char composicao[20];
  int tipo; // tipo = 1 (Arroz), tipo = 2 (Feij�o)
};

struct sobremesa {
  char composicao[20];
  int tipo; // tipo = 1 (Fruta); tipo = 2 (Doce);
};

struct cardapio {
  int semana;
  struct proteina opcao1[5];
  struct proteina opcao2[5];
  struct proteina vegetariana[5];
  struct guarnicao guarnicoes[5];
  struct acompanhamento acompanhamento[5];
  struct sobremesa sobremesa[5];
};

// NESTA PARTE VAO FICAR AS FUNCOES
// M�dulos para a fun��o addProteina()
void addProteina() {
  struct proteina ptn;
  fptr = fopen("bd_proteinas.txt", "a");
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

void addGuarnicao() {
  struct guarnicao gnc;
  fptr = fopen("bd_gncs.txt", "a");
  printf("COMPOSI��O DA GUARNI��O: ");
  scanf(" %[^\n]s", gnc.nome);
  fprintf(fptr, "\n%s", gnc.nome);
  fclose(fptr);
}

void addAcompanhamento() {
  struct acompanhamento acpmt;
  fptr = fopen("bd_acpmt.txt", "a");
  printf("COMPOSI��O DA GUARNI��O: ");
  scanf(" %[^\n]s", acpmt.composicao);
  printf("TIPO DE GUARNI��O (1 - ARROZ; 2 - FEIJAO): ");
  scanf(" %d", &acpmt.tipo);
  fprintf(fptr, "%s\n%d\n", acpmt.composicao, acpmt.tipo);
  fclose(fptr);
}

void addSobremesa() {
  struct sobremesa sbms;
  fptr = fopen("bd_sbms.txt", "a");
  printf("COMPOSI��O SOBREMESA: ");
  scanf(" %[^\n]s", sbms.composicao);
  printf("TIPO DE SOBREMESA (1 - FRUTA; 2 - DOCE): ");
  scanf("%d", &sbms.tipo);
  fprintf(fptr, "%s\n%d\n", sbms.composicao, sbms.tipo);
  fclose(fptr);
}
// Fun��o  para adicionar opcoes de cardapio: proteina, vegetariana,
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

// Fun��o  para editar alguma op��o.
void editOpcao() {}

// Fun��o  para deletar alguma op��es
void deleteOpcao() {}

// Fun��o para mostrar op��es dispon�veis para montar card�pio.
// M�dulo para a fun��o displayOpcoesDisp()
void displayProteina() {
  int id = 1;
  fptr = fopen("bd_proteinas.txt", "r");
  struct proteina ptn;
  if (fptr == NULL) {
    printf("Erro to open the bd_proteinas.txt");
    exit(1);
  }
  // Header
  printf("|                           OP��ES DE PROTE�NA DISPON�VEL                      |\n");
  printf("|------------------------------------------------------------------------------|\n");
  printf("| ID  |            NOME            |            POR��O            |    TIPO    |\n");
  printf("|-----|----------------------------|------------------------------|------------|\n");
  do {
    fgets(ptn.nome, 20, fptr);
    ptn.nome[strlen(ptn.nome) - 1] = 0; // Removendo \n
    fscanf(fptr, " %d", &ptn.porcao);
    fscanf(fptr, " %d", &ptn.tipo);
    printf("| %-4d|   %-25s|              %3d             |      %d     |\n", id, ptn.nome,
           ptn.porcao, ptn.tipo);
    id++;
  } while (!feof(fptr));
  printf("\n");
  system("PAUSE");
} 

void displayGuarnicao() {
  fptr = fopen("bd_gncs.txt", "r");
  struct guarnicao gnc;
  if (fptr == NULL) {
    printf("Erro to open the bd_salada.txt");
    exit(1);
  }
   // Header
  printf("|  OP��ES DE GUARNI��ES |\n");
  printf("|-----------------------|\n");
  printf("|        NOME           |\n");
  printf("|-----------------------|\n");
  do {
    fgets(gnc.nome, 20, fptr);
    gnc.nome[strlen(gnc.nome) - 1] = 0; // Removendo \n
    printf("|   %-20s|\n", 
    gnc.nome);
  } while (!feof(fptr));
  printf("\n");
  system("PAUSE");
}

void displaySalada() {
  fptr = fopen("bd_salada.txt", "r");
  struct salada sld;
  if (fptr == NULL) {
    printf("Erro to open the bd_salada.txt");
    exit(1);
  }
  // Header
  printf("|                           OP��ES DE SALADA                             |\n");
  printf("|------------------------------------------------------------------------|\n");
  printf("|                  COMOPOSI��O                     | QUANTIDADE DE ITENS |\n");
  printf("|--------------------------------------------------|---------------------|\n");

  do {
    fgets(sld.composicao, 60, fptr);
    sld.composicao[strlen(sld.composicao) - 1] = 0; // Removendo \n
    fscanf(fptr, "  %d\n", &sld.qunatItens);

  printf("|   %-40s       |         %d           |\n", 
    sld.composicao, sld.qunatItens);
  } while (!feof(fptr));
  printf("\n");
  system("PAUSE");
}

void displayAcompanhamento() {
  fptr = fopen("bd_acpmt.txt", "r");
  struct acompanhamento acpmt;
  if (fptr == NULL) {
    printf("Erro to open the bd_acpmt.txt");
    exit(1);
  }
  // Header
  printf("|                           OP��ES DE ACOMPANHAMENTO                     |\n");
  printf("|------------------------------------------------------------------------|\n");
  printf("|                  COMOPOSI��O                     |         TIPO        |\n");
  printf("|--------------------------------------------------|---------------------|\n");

  do {
    fgets(acpmt.composicao, 60, fptr);
    acpmt.composicao[strlen(acpmt.composicao) - 1] = 0; // Removendo \n
    fscanf(fptr, "  %d\n", &acpmt.tipo);
    printf("|   %-40s       |         %d           |\n", acpmt.composicao, acpmt.tipo);
  } while (!feof(fptr));
  printf("\n");
  system("PAUSE");
}

void displaySobremesa() {
  fptr = fopen("bd_sbms.txt", "r");
  struct sobremesa sbms;
  if (fptr == NULL) {
    printf("Erro to open the bd_sbms.txt");
    exit(1);
  }
  // Header
  printf("|                          OP��ES DE SOBREMESA                           |\n");
  printf("|------------------------------------------------------------------------|\n");
  printf("|                  COMOPOSI��O                     |         TIPO        |\n");
  printf("|--------------------------------------------------|---------------------|\n");

  do {
    fgets(sbms.composicao, 20, fptr);
    sbms.composicao[strlen(sbms.composicao) - 1] = 0; // Removendo \n
    fscanf(fptr, "  %d\n", &sbms.tipo);
    printf("|   %-40s       |         %d           |\n", sbms.composicao, sbms.tipo);
  } while (!feof(fptr));
  printf("\n");
  system("PAUSE");
}

void displayOpcoesDisp() {
  // Menu do displayOpcoesDisp()
  printf("\n\n PRESSIONE: ");
  printf("\n 1.) MOSTRAR OP��ES DE PROTE�NA.");
  printf("\n 2.) MOSTRAR OP��ES DE SALADA.");
  printf("\n 3.) MOSTRAR OP��ES DE GUARNI��O.");
  printf("\n 4.) MOSTRAR OP��ES DE ACOMPANHAMENTO.");
  printf("\n 5.) MOSTRAR OP��ES DE SOBREMESA.");
  printf("\n 6.) VOLTAR.");
  printf("\nESCOLHA--> ");
  scanf("%d", &choice);
  switch (choice) {
  case 1: // Mostrar op��es de prote�na dispon�veis.
    displayProteina();
    break;
  case 2: // Mostrar op��es de salada.
    displaySalada();
    break;
  case 3: // Mostrar op��es de guarni��o.
    displayGuarnicao();
    break;
  case 4: // Mostrar op��es de acompanhamento.
    displayAcompanhamento();
    break;
  case 5: // Mostrar op��es de sobremesa.
    displaySobremesa();
    break;
  case 6: // Voltando ao menu anterior.
    printf("Voltando");
    break;
  default:
    printf("Op��o Inv�lida.");
  }
}

// funcao para mostrar o cardapio
void showCardapio() {}

// funcao para fazer o card�pio
void makeCardapio() {}

int main(void) {
  // Definindo variaveis e constantes
  int i;
  struct cardapio cdpo;

  do {
    system("cls");
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
    scanf(" %d", &choice);
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
      printf("\nVOCE NAO ESCOLHEU UMA OP��O V�LIDA");
      main();
      continue;
    }
  } while (choice != 7);
  printf("OBRIGADO POR USAR O PROGRAMA.");
}
