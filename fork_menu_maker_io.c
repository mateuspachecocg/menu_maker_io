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
  int tipo;             // tipo = 1 (Opá∆o 1), tipo = 2 (Opá∆o 2, CONTêM FRANGO), tipo
                        // = 3 (Opá∆o Vegetariana)
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
  int tipo;              // tipo = 1 (Arroz), tipo = 2 (Feij∆o)
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
    count_ptn   = 0,  // Quantidade de opá‰es de proteina dispon°veis.
    count_gnc   = 0,  // Quantidade de opá‰es de guarniá‰es dispon°veis.
    count_sld   = 0,  // Quantidade de opá‰es de salada dispon°veis.
    count_acpmt = 0,  // Quantidade de opá‰es de acompanhamento dispon°veis.
    count_sbms  = 0;  // Quantidade de opáoes de sobremesa dispon°veis. 

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
// M¢dulos para a funá∆o addProteina()
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
  printf("COMPOSIÄ«O DA SALADA: ");
  scanf(" %[^\n]s", sld.composicao);
  printf("\nQUANTIDADE DE ITENS QUE COMPÂEM A SALADA: ");
  scanf(" %d", &sld.quantItens);
  fprintf(fptr, "\n%s\n%d", sld.composicao, sld.quantItens);
  fclose(fptr);
}

void addGuarnicao() {
  struct guarnicao gnc;
  fptr = fopen("bd_gncs.txt", "a");
  printf("COMPOSIÄ«O DA GUARNIÄ«O: ");
  scanf(" %[^\n]s", gnc.nome);
  fprintf(fptr, "\n%s", gnc.nome);
  fclose(fptr);
}

void addAcompanhamento() {
  struct acompanhamento acpmt;
  fptr = fopen("bd_acpmt.txt", "a");
  printf("COMPOSIÄ«O DA GUARNIÄ«O: ");
  scanf(" %[^\n]s", acpmt.composicao);
  printf("TIPO DE GUARNIÄ«O (1 - ARROZ; 2 - FEIJAO): ");
  scanf(" %d", &acpmt.tipo);
  fprintf(fptr, "%s\n%d\n", acpmt.composicao, acpmt.tipo);
  fclose(fptr);
}

void addSobremesa() {
  struct sobremesa sbms;
  fptr = fopen("bd_sbms.txt", "a");
  printf("COMPOSIÄ«O SOBREMESA: ");
  scanf(" %[^\n]s", sbms.composicao);
  printf("TIPO DE SOBREMESA (1 - FRUTA; 2 - DOCE): ");
  scanf("%d", &sbms.tipo);
  fprintf(fptr, "%s\n%d\n", sbms.composicao, sbms.tipo);
  fclose(fptr);
}
// Funá∆o  para adicionar opcoes de cardapio: proteina, vegetariana,
// acompanhamento, sobremesa.
void addOpcao() {
  // Menu do addOpcao()
  printf("\n\n PRESSIONE: ");
  printf("\n 1.) INSERIR OPÄ«O DE PROTE÷NA.");
  printf("\n 2.) INSERIR OPÄ«O DE SALADA.");
  printf("\n 3.) INSERIR OPÄ«O DE GUARNIÄ«O.");
  printf("\n 4.) INSERIR OPÄ«O DE ACOMPANHAMENTO.");
  printf("\n 5.) INSERIR OPÄ«O DE SOBREMESA.");
  printf("\n 6.) VOLTAR.");
  printf("\nESCOLHA--> ");
  scanf("%d", &choice);
  switch (choice) {
  case 1: // Adcionar prote√≠na
    addProteina();
    break;
  case 2: // Adiconar salada.
    addSalada();
    break;
  case 3: // Adiconar guarniá∆o.
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
    printf("Opá∆o Inv†lida.");
  }
}

// Funá∆o  para editar alguma opá∆o.
void editOpcao() {}

// Funá∆o  para deletar alguma opá‰es
void deleteOpcao() {}

// Funá∆o para mostrar opá‰es dispon°veis para montar card†pio.
// M¢dulo para a funá∆o displayOpcoesDisp()
void displayProteina() {
  int i;
  lerArquivos(1);
  // Header
  printf("|                           OPÄÂES DE PROTE÷NA DISPON÷VEL                      |\n");
  printf("|------------------------------------------------------------------------------|\n");
  printf("| ID  |            NOME            |            PORÄ«O            |    TIPO    |\n");
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
  printf("|  OPÄÂES DE GUARNIÄÂES |\n");
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
  printf("|                           OPÄÂES DE SALADA                             |\n");
  printf("|------------------------------------------------------------------------|\n");
  printf("|                  COMOPOSIÄ«O                     | QUANTIDADE DE ITENS |\n");
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
  printf("|                           OPÄÂES DE ACOMPANHAMENTO                     |\n");
  printf("|------------------------------------------------------------------------|\n");
  printf("|                  COMOPOSIÄ«O                     |         TIPO        |\n");
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
  printf("|                          OPÄÂES DE SOBREMESA                           |\n");
  printf("|------------------------------------------------------------------------|\n");
  printf("|                  COMOPOSIÄ«O                     |         TIPO        |\n");
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
  printf("\n 1.) MOSTRAR OPÄÂES DE PROTE÷NA.");
  printf("\n 2.) MOSTRAR OPÄÂES DE SALADA.");
  printf("\n 3.) MOSTRAR OPÄÂES DE GUARNIÄ«O.");
  printf("\n 4.) MOSTRAR OPÄÂES DE ACOMPANHAMENTO.");
  printf("\n 5.) MOSTRAR OPÄÂES DE SOBREMESA.");
  printf("\n 6.) VOLTAR.");
  printf("\nESCOLHA--> ");
  scanf("%d", &choice);
  switch (choice) {
  case 1: // Mostrar opá‰es de prote°na dispon°veis.
    displayProteina();
    break;
  case 2: // Mostrar opá‰es de salada.
    displaySalada();
    break;
  case 3: // Mostrar opá‰es de guarniá∆o.
    displayGuarnicao();
    break;
  case 4: // Mostrar opá‰es de acompanhamento.
    displayAcompanhamento();
    break;
  case 5: // Mostrar opá‰es de sobremesa.
    displaySobremesa();
    break;
  case 6: // Voltando ao menu anterior.
    printf("Voltando");
    break;
  default:
    printf("Opá∆o Inv†lida.");
  }
}

// funcao para mostrar o cardapio
void showCardapio() {}

// funcao para fazer o card†pio
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
    printf("\n 1.) INSERIR OPÄÂES.");
    printf("\n 2.) EDITAR OPÄ«O");
    printf("\n 3.) DELETAR OPÄ«O");
    printf("\n 4.) MOSTRAR OPÄÂES DISPONIVEIS");
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
    case 3: // DELETAR UMA OPÄ«O
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
      printf("\nVOCE NAO ESCOLHEU UMA OPÄ«O VµLIDA");
      main();
      continue;
    }
  } while (choice != 7);
  printf("OBRIGADO POR USAR O PROGRAMA.");
}
