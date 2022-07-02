#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Usada para remover \n na leitura dos txt
#include <time.h>    // Usada na hora de gerar o card†pio randìmico.
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
  struct salada salada[5];
  struct guarnicao guarnicoes[5];
  struct acompanhamento acompanhamento[5];
  struct sobremesa sobremesa[5];
};

// Global variables
struct proteina       vetor_proteinas[25];       // Vetor para armazenas opá‰es de proteinas dispon°veis.
struct guarnicao      vetor_guarnicao[25];       // Vetor para armazenas opá‰es de guarniá‰es dispon°veis.
struct salada         vetor_salada[25];          // Vetor para armazenas opá‰es de salada dispon°veis.
struct acompanhamento vetor_acompanhamento[25];  // Vetor para armazenas opá‰es de acompanhamento dispon°veis.
struct sobremesa      vetor_sobremesa[25];       // Vetor para armazenas opá‰es de sobremesa dispon°veis.
struct cardapio       vetor_cardapios[42];       // Vetor para armazenar card†pios gerados.
FILE *fptr; // Ponteiro para controlar arquivos
int choice,   
    count_ptn   = 0,  // Quantidade de opá‰es de proteina dispon°veis.
    count_gnc   = 0,  // Quantidade de opá‰es de guarniá‰es dispon°veis.
    count_sld   = 0,  // Quantidade de opá‰es de salada dispon°veis.
    count_acpmt = 0,  // Quantidade de opá‰es de acompanhamento dispon°veis.
    count_sbms  = 0,  // Quantidade de opáoes de sobremesa dispon°veis. 
    count_cdpo  = 0;  // Quantidade de card†pios armazenados no sistema.

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
  
  case 6: // escrever arquivo bd_cardapios.txt
    fptr = fopen("bd_cardapios.txt", "w");
    if (fptr == NULL) {
      return - 1;
    }
    fprintf(fptr, "%d\n", count_cdpo);
    for (i = 0; i < count_cdpo; i++){
      vetor_cardapios[i].semana = i + 1;
      // Gravando cdpo no arquivo
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
      return 0;
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
      return 0;
    }
    fscanf(fptr, "%d\n", &count_gnc);
    for (i = 0; i < count_gnc; i++){
      fscanf(fptr, "%d\n", &vetor_guarnicao[i].id);
      fgets(vetor_guarnicao[i].nome, 50, fptr);
      vetor_guarnicao[i].nome[strlen(vetor_guarnicao[i].nome) - 1] = 0; // Removendo \n
    }
    return count_gnc;
    break;
  case 3: // ler arquivo bd_salada.txt
    fptr = fopen("bd_salada.txt", "r");
    if (fptr == NULL) {
      return 0;
    }
    fscanf(fptr, "%d\n", &count_sld);
    for(i =0; i < count_sld; i++){
      fscanf(fptr, "%d\n", &vetor_salada[i].id);
      fgets(vetor_salada[i].composicao, 50, fptr);
      vetor_salada[i].composicao[strlen(vetor_salada[i].composicao) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_salada[i].quantItens);
    }
    return count_sld;
    break;
  case 4: // ler arquivo bd_acpmt.txt
    fptr = fopen("bd_acpmt.txt", "r");
    if (fptr == NULL) {
      return 0;
    }
    fscanf(fptr, "%d\n", &count_acpmt);
    for (i = 0; i < count_acpmt; i++){
      fscanf(fptr, "%d\n", &vetor_acompanhamento[i].id);
      fgets(vetor_acompanhamento[i].composicao, 50, fptr);
      vetor_acompanhamento[i].composicao[strlen(vetor_acompanhamento[i].composicao) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_acompanhamento[i].tipo);
    }
    return count_acpmt;
    break;
  case 5: // ler arquivo bd_sbms.txt
    fptr = fopen("bd_smbs.txt", "r");
    if (fptr == NULL) {
      return 0;
    }
    fscanf(fptr, "%d\n", &count_sbms);
    for(i =0; i < count_sbms; i++){
      fscanf(fptr, "%d\n", &vetor_sobremesa[i].id);
      fgets(vetor_sobremesa[i].composicao, 50, fptr);
      vetor_sobremesa[i].composicao[strlen(vetor_sobremesa[i].composicao) - 1] = 0; // Removendo \n
      fscanf(fptr, " %d", &vetor_sobremesa[i].tipo); 
    }
    return count_sbms;
    break;
  
  
  case 6: // ler arquivo bd_cardapios
    break;
  }
}

// NESTA PARTE VAO FICAR AS FUNCOES
// M¢dulos para a funá∆o menuAddOpcao()

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

void addGuarnicao() {
  struct guarnicao gnc;
  fptr = fopen("bd_gncs.txt", "a");
  printf("COMPOSIÄ«O DA GUARNIÄ«O: ");
  scanf(" %[^\n]s", gnc.nome);
  vetor_guarnicao[count_gnc] = gnc;
  count_gnc++;
  escreverArquivo(2);
}


void addSalada() {
  struct salada sld;
  printf("COMPOSIÄ«O DA SALADA: ");
  scanf(" %[^\n]s", sld.composicao);
  printf("\nQUANTIDADE DE ITENS QUE COMPÂEM A SALADA: ");
  scanf(" %d", &sld.quantItens);
  vetor_salada[count_sld] = sld;
  count_sld++;
  escreverArquivo(3);
}

void addAcompanhamento() {
  struct acompanhamento acpmt;
  printf("COMPOSIÄ«O DO ACOMPANHAMENTO: ");
  scanf(" %[^\n]s", acpmt.composicao);
  printf("TIPO DE ACOMPANHAMENTO (1 - ARROZ; 2 - FEIJAO): ");
  scanf(" %d", &acpmt.tipo);
  vetor_acompanhamento[count_acpmt] = acpmt;
  count_acpmt++;
  escreverArquivo(4);
}

void addSobremesa() {
  struct sobremesa sbms;
  printf("COMPOSIÄ«O SOBREMESA: ");
  scanf(" %[^\n]s", sbms.composicao);
  printf("TIPO DE SOBREMESA (1 - FRUTA; 2 - DOCE): ");
  scanf("%d", &sbms.tipo);
  vetor_sobremesa[count_sbms] = sbms;
  count_sbms++;
  escreverArquivo(5);
}


void menuAddOpcao() { // Funá∆o  para adicionar opcoes de cardapio
  system("cls");
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


void editOpcao() { // Funá∆o  para editar alguma opá∆o.
  
}

void deleteOpcao() { // Funá∆o  para deletar alguma opá‰es

}

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
    printf("|-----|----------------------------|------------------------------|------------|\n");
  }
  printf("\n");
  system("PAUSE");
} 

void displayGuarnicao() {
  int i;
   // Header
  printf("|     OPÄÂES DE GUARNIÄÂES    |\n");
  printf("|-----------------------------|\n");
  printf("| ID  |        NOME           |\n");
  printf("|-----|-----------------------|\n");
  for (i = 0; i  < count_gnc; i++){
    printf("| %-4d|   %-20s|\n", 
            vetor_guarnicao[i].id,
            vetor_guarnicao[i].nome);
    printf("|-----|-----------------------|\n");
  }
  printf("\n");
  system("PAUSE");
}

void displaySalada() {
  int i;
  // Header
  printf("|                               OPÄÂES DE SALADA                               |\n");
  printf("|------------------------------------------------------------------------------|\n");
  printf("| ID  |                  COMOPOSIÄ«O                     | QUANTIDADE DE ITENS |\n");
  printf("|-----|--------------------------------------------------|---------------------|\n");
  for (i = 0; i < count_sld; i++){
    printf("| %-4d|   %-40s       |         %d           |\n", 
            vetor_salada[i].id,
            vetor_salada[i].composicao, 
            vetor_salada[i].quantItens);
    printf("|-----|--------------------------------------------------|---------------------|\n");

  }
  printf("\n");
  system("PAUSE");
}

void displayAcompanhamento() {
  int i;
  // Header
  printf("|                             OPÄÂES DE ACOMPANHAMENTO                         |\n");
  printf("|------------------------------------------------------------------------------|\n");
  printf("| ID  |                  COMOPOSIÄ«O                     |         TIPO        |\n");
  printf("|-----|--------------------------------------------------|---------------------|\n");
  for (i = 0; i < count_acpmt; i++){
    printf("| %-4d|   %-40s       |         %d           |\n", 
          vetor_acompanhamento[i].id,
          vetor_acompanhamento[i].composicao,
          vetor_acompanhamento[i].tipo);
    printf("|-----|--------------------------------------------------|---------------------|\n");

  }
  printf("\n");
  system("PAUSE");
}

void displaySobremesa() {
  int i;
  // Header
  printf("|                                OPÄÂES DE SOBREMESA                           |\n");
  printf("|------------------------------------------------------------------------------|\n");
  printf("| ID  |                  COMOPOSIÄ«O                     |         TIPO        |\n");
  printf("|-----|--------------------------------------------------|---------------------|\n");
  for (i = 0; i < count_sbms; i++){
    printf("| %-4d|   %-40s       |         %d           |\n", 
            vetor_sobremesa[i].id,
            vetor_sobremesa[i].composicao,
            vetor_sobremesa[i].tipo);
    printf("|-----|--------------------------------------------------|---------------------|\n");
  }
  printf("\n");
  system("PAUSE");

}

void displayOpcoesDisp() { // Funá∆o para mostrar opá‰es dispon°veis para montar card†pio.
  system("cls");
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

void showCardapio(int id) { // funcao para mostrar o cardapio
    struct cardapio cdpo = vetor_cardapios[id];
    printf("|----------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                  CARDAPIO DA SEMANA %d                                                      |\n",
            cdpo.semana);
    printf("|----------------------------------------------------------------------------------------------------------------------------|\n");
    printf("|      ALMOÄO      |       SEGUNDA       |        TERÄA        |       QUARTA       |       QUINTA       |       SEXTA       |\n");
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
    printf("|      OPÄ«O 1     |%-19s|%-19s|%-19s|%-20s|%-19s|\n",
            cdpo.opcao1[0].nome, 
            cdpo.opcao1[1].nome, 
            cdpo.opcao1[2].nome, 
            cdpo.opcao1[3].nome, 
            cdpo.opcao1[4].nome);
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
    printf("|      OPÄ«O 2     |%-19s|%-19s|%-19s|%-20s|%-19s|\n",
            cdpo.opcao2[0].nome, 
            cdpo.opcao2[1].nome, 
            cdpo.opcao2[2].nome, 
            cdpo.opcao2[3].nome, 
            cdpo.opcao2[4].nome);
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
    printf("|    VEGETARIANA   |%-19s|%-19s|%-19s|%-20s|%-19s|\n",
            cdpo.vegetariana[0].nome, 
            cdpo.vegetariana[1].nome, 
            cdpo.vegetariana[2].nome, 
            cdpo.vegetariana[3].nome, 
            cdpo.vegetariana[4].nome);
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
    printf("|      SALADA      |%-19s|%-19s|%-19s|%-20s|%-19s|\n",
            cdpo.salada[0].composicao, 
            cdpo.salada[1].composicao, 
            cdpo.salada[2].composicao, 
            cdpo.salada[3].composicao, 
            cdpo.salada[4].composicao);
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
    printf("|  ACOMPANHAMENTO  |%-19s|%-19s|%-19s|%-20s|%-19s|\n",
            cdpo.acompanhamento[0].composicao, 
            cdpo.acompanhamento[1].composicao,
            cdpo.acompanhamento[2].composicao, 
            cdpo.acompanhamento[3].composicao,
            cdpo.acompanhamento[4].composicao);
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
    printf("|     SOBREMESA    |%-19s|%-19s|%-19s|%-20s|%-19s|\n",
            cdpo.sobremesa[0].composicao,
            cdpo.sobremesa[1].composicao,
            cdpo.sobremesa[2].composicao,
            cdpo.sobremesa[3].composicao,
            cdpo.sobremesa[4].composicao);
    printf("|------------------|---------------------|---------------------|--------------------|--------------------|-------------------|\n");
}

void menuShowcardapio(){

}

void makeCardapio() { // Funá∆o para gerar um card†pio randìmico
  int i, index_rand;
  int sortedIndex[5];
  // Configurando funá∆o de randimicidade.
  time_t t1;
  srand((unsigned) time(&t1));
  // Gerando OPÄ∂O 1 de Prote°na
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    if ( vetor_proteinas[index_rand].tipo == 1) { // Checando se a prote°na Ç do tipo 1
      vetor_cardapios[count_cdpo].opcao1[i] = vetor_proteinas[index_rand];
      sortedIndex[i] = index_rand;
      i++; // 
    }
  }
  // Gerando OPÄ∂O 2 de Prote°na
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    if ( vetor_proteinas[index_rand].tipo == 2) { // Checando se a prote°na Ç do tipo 1
      vetor_cardapios[count_cdpo].opcao2[i] = vetor_proteinas[index_rand];
      sortedIndex[i] = index_rand;
      i++; // 
    }
  }
  // Gerando OPÄ«O vegetariana.
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    if ( vetor_proteinas[index_rand].tipo == 3) { // Checando se a prote°na Ç do tipo 1
      vetor_cardapios[count_cdpo].vegetariana[i] = vetor_proteinas[index_rand];
      sortedIndex[i] = index_rand;
      i++; // 
    }
  }
  // Gerando salada
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    vetor_cardapios[count_cdpo].salada[i] = vetor_salada[index_rand];
    sortedIndex[i] = index_rand;
    i++; 
  }
  // Gerando Guariá∆o
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    vetor_cardapios[count_cdpo].guarnicoes[i] = vetor_guarnicao[index_rand];
    sortedIndex[i] = index_rand;
    i++;
  }
  // Gerando acompanhamento
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    vetor_cardapios[count_cdpo].acompanhamento[i] = vetor_acompanhamento[index_rand];
    sortedIndex[i] = index_rand;
    i++;
  }
  // Gerando sobremesa 
  for (i = 0; i < 5; ){
    index_rand = rand()%count_ptn;
    // Verificar se o index_rand j† saiu antes.
    vetor_cardapios[count_cdpo].sobremesa[i] = vetor_sobremesa[index_rand];
    sortedIndex[i] = index_rand;
    i++;
  }
  // Atualizando a quantidade de card†pios armazenados
  count_cdpo++;
  escreverArquivo(6);
}

int main(void) {
  // Definindo variaveis e constantes
  int i;
  // Lendo arquivos com dados armazenados.
  count_ptn   = lerArquivos(1);
  count_gnc   = lerArquivos(2);
  count_sld   = lerArquivos(3);
  count_acpmt = lerArquivos(4);
  count_sbms  = lerArquivos(5);
  count_cdpo  = lerArquivos(6);

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
      menuAddOpcao();
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
      menuShowcardapio();
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
