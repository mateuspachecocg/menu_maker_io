#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

// Definindo structs
struct proteina {
  int id;
  char nome[50];
  int porcao;
  int tipo;             // tipo = 1 (Op��o 1), tipo = 2 (Op��o 2, CONT�M FRANGO), tipo
                        // = 3 (Op��o Vegetariana)
};

struct guarnicao {
  int id;
  char nome[40];
};

struct salada {
  int id;
  char composicao[60];
  int quantItens;
};

struct acompanhamento {
  int id;
  char composicao[20];
  int tipo;              // tipo = 1 (Arroz), tipo = 2 (Feij�o)
};

struct sobremesa {
  int id;
  char composicao[20];
  int tipo;              // tipo = 1 (Fruta); tipo = 2 (Doce);
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

// Global variables
struct proteina       vetor_proteinas[25];
struct guarnicao      vetor_guarnicao[25];
struct salada         vetor_salada[25];
struct acompanhamento vetor_acompanhamento[25];
struct sobremesa      vetor_sobremesa[25];
FILE *fptr; // Ponteiro para controlar arquivos
int choice,   
    count_ptn   = 0,  // Quantidade de op��es de proteina dispon�veis.
    count_gnc   = 0,  // Quantidade de op��es de guarni��es dispon�veis.
    count_sld   = 0,  // Quantidade de op��es de salada dispon�veis.
    count_acpmt = 0,  // Quantidade de op��es de acompanhamento dispon�veis.
    count_sbms  = 0;  // Quantidade de op�oes de sobremesa dispon�veis. 

int escreverArquivo(int tipo){
  int i;
  switch (tipo) {
  case 1: // escrever arquivo bd_proteinas.txt
    fptr = fopen("bd_proteinas.txt", "w");
    if (fptr == NULL) {
      return - 1;
    }
    fprintf(fptr, "%d\n", count_ptn);
    for (i = 0; i < count_ptn; i++)
    { 
      vetor_proteinas[i].id = i + 1;
      fprintf(fptr, "%d\n", vetor_proteinas[i].id);
      fprintf(fptr, "%s\n", vetor_proteinas[i].nome);
      fprintf(fptr, "%d\n", vetor_proteinas[i].porcao);
      fprintf(fptr, "%d\n", vetor_proteinas[i].tipo);
    }
    break;
  case 2: // escrever arquivo bd_gncs.txt
    fptr = fopen("bd_gncs.txt", "w");
    if (fptr == NULL) {
      return - 1;
    }
    fprintf(fptr, "%d\n", count_gnc);
    for(i = 0; i < count_gnc; i++){
      vetor_guarnicao[i].id = i + 1;
      fprintf(fptr, "%d\n", vetor_guarnicao[i].id);
      fprintf(fptr, "%s\n", vetor_guarnicao[i].nome);
    }
    break;
  case 3: // escrever arquivo bd_salada.txt
    fptr = fopen("bd_salada.txt", "w");
    if (fptr == NULL) {
      return - 1;
    }
    fprintf(fptr, "%d\n", count_sld);
    for (i = 0; i < count_sld; i++){
      vetor_salada[i].id = i + 1;
      fprintf(fptr, "%d\n", vetor_salada[i].id);
      fprintf(fptr, "%s\n", vetor_salada[i].composicao);
      fprintf(fptr, "%d\n", vetor_salada[i].quantItens);
    }
    break;
  case 4: // escrever arquivo bd_acpmt.txt
    fptr = fopen("bd_acpmt.txt", "w");
    if (fptr == NULL) {
      return - 1;
    }
    fprintf(fptr, "%d\n", count_acpmt);
    for (i = 0;i < count_acpmt; i++){
      vetor_acompanhamento[i].id = i + 1;
      fprintf(fptr, "%d\n", vetor_acompanhamento[i].id);
      fprintf(fptr, "%s\n", vetor_acompanhamento[i].composicao);
      fprintf(fptr, "%d\n", vetor_acompanhamento[i].tipo);
    }
    break;
  case 5: // escrever arquivo bd_sbms.txt
    fptr = fopen("bd_smbs.txt", "w");
    if (fptr == NULL) {
      return - 1;
    }
    fprintf(fptr, "%d\n", count_sbms);
    for (i = 0; i < count_sbms; i++){
      vetor_sobremesa[i].id = i + 1;
      fprintf(fptr, "%d\n", vetor_sobremesa[i].id);
      fprintf(fptr, "%s\n", vetor_sobremesa[i].composicao);
      fprintf(fptr, "%d\n", vetor_sobremesa[i].tipo);
    }
    break;
  }
  fclose(fptr);
  return 0;
}

int lerArquivos(int tipo){
  int i;
  switch (tipo) {
  case 1: // ler arquivo bd_proteinas.txt
    fptr = fopen("bd_proteinas.txt", "r");
    if (fptr == NULL) {
      return - 1;
    }
    fscanf(fptr, "%d\n", &count_ptn);
    for(i =0; i < count_ptn; i++)
    {
      fscanf(fptr, "%d\n", &vetor_proteinas[i].id);
      fgets(vetor_proteinas[i].nome, 50, fptr);
      vetor_proteinas[i].nome[strlen(vetor_proteinas[i].nome) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_proteinas[i].porcao);
      fscanf(fptr, " %d", &vetor_proteinas[i].tipo);
    }
    fclose(fptr);
    return count_ptn;
    break;
  case 2: // ler arquivo bd_gncs.txt
    fptr = fopen("bd_gncs.txt", "r");
    if (fptr == NULL) {
      return - 1;
    }
    fscanf(fptr, "%d\n", &count_gnc);
    for (i = 0; i < count_gnc; i++){
      fscanf(fptr, "%d\n", &vetor_guarnicao[i].id);
      fgets(vetor_guarnicao[i].nome, 50, fptr);
      vetor_guarnicao[i].nome[strlen(vetor_guarnicao[i].nome) - 1] = 0; // Removendo \n
    }
    break;
  case 3: // ler arquivo bd_salada.txt
    fptr = fopen("bd_salada.txt", "r");
    if (fptr == NULL) {
      return - 1;
    }
    fscanf(fptr, "%d\n", &count_sld);
    for(i =0; i < count_sld; i++){
      fscanf(fptr, "%d\n", &vetor_salada[i].id);
      fgets(vetor_salada[i].composicao, 50, fptr);
      vetor_salada[i].composicao[strlen(vetor_salada[i].composicao) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_salada[i].quantItens);
    }
    break;
  case 4: // ler arquivo bd_acpmt.txt
    fptr = fopen("bd_acpmt.txt", "r");
    if (fptr == NULL) {
      return - 1;
    }
    fscanf(fptr, "%d\n", &count_acpmt);
    for (i = 0; i < count_acpmt; i++){
      fscanf(fptr, "%d\n", &vetor_acompanhamento[i].id);
      fgets(vetor_acompanhamento[i].composicao, 50, fptr);
      vetor_acompanhamento[i].composicao[strlen(vetor_acompanhamento[i].composicao) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_acompanhamento[i].tipo);
    }
    break;
  case 5: // ler arquivo bd_sbms.txt
    fptr = fopen("bd_smbs.txt", "r");
    if (fptr == NULL) {
      return - 1;
    }
    fscanf(fptr, "%d\n", &count_sbms);
    for(i =0; i < count_sbms; i++){
      fscanf(fptr, "%d\n", &vetor_sobremesa[i].id);
      fgets(vetor_sobremesa[i].composicao, 50, fptr);
      vetor_sobremesa[i].composicao[strlen(vetor_sobremesa[i].composicao) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_sobremesa[i].tipo); 
    }
    break;
  return 1; 
  }
}


// NESTA PARTE VAO FICAR AS FUNCOES
// M�dulos para a fun��o addProteina()
void addProteina() {
  struct proteina ptn;
  printf("NOME DA PROTEINA: ");
  scanf(" %[^\n]s", ptn.nome);
  printf("\nQUANTIDADE EM GRAMAS SERVIDA: ");
  scanf("%d", &ptn.porcao);
  printf("\nTIPO DE PROTEINA: ");
  scanf("%d", &ptn.tipo);
  vetor_proteinas[count_ptn] = ptn;
  count_ptn++;
  escreverArquivo(1);
}

void addSalada() {
  struct salada sld;
  fptr = fopen("bd_salada.txt", "a");
  printf("COMPOSI��O DA SALADA: ");
  scanf(" %[^\n]s", sld.composicao);
  printf("\nQUANTIDADE DE ITENS QUE COMP�EM A SALADA: ");
  scanf(" %d", &sld.quantItens);
  fprintf(fptr, "\n%s\n%d", sld.composicao, sld.quantItens);
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
  int i;
  lerArquivos(1);
  // Header
  printf("|                           OP��ES DE PROTE�NA DISPON�VEL                      |\n");
  printf("|------------------------------------------------------------------------------|\n");
  printf("| ID  |            NOME            |            POR��O            |    TIPO    |\n");
  printf("|-----|----------------------------|------------------------------|------------|\n");
  for(i = 0; i < count_ptn; i++)
  {
    printf("| %-4d|   %-25s|              %3d             |      %d     |\n", 
    vetor_proteinas[i].id,
    vetor_proteinas[i].nome,
    vetor_proteinas[i].porcao, 
    vetor_proteinas[i].tipo);
  }
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
    fscanf(fptr, "  %d\n", &sld.quantItens);

  printf("|   %-40s       |         %d           |\n", 
    sld.composicao, sld.quantItens);
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
  count_ptn = lerArquivos(1);

  do { //Menu Inicial do Programa
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
