#include <stdio.h>
#include <stdlib.h>
#define true 0
#define false 1

// Definindo structs
struct proteina{
  char nome[20];
};

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

// NESTA PARTE VAO FICAR AS FUNCOES

// funcao para adicionar opcoes de cardapio: proteina, vegetariana, acompanhamento, sobremesa.
void addOpcao(){

}

// funcao para editar alguma opção de CARDAPIO
void editOpcao(){

}

// funcao para deletar alguma opção de CARDAPIO
void deleteOpcao(){

}

// funcao para mostrar as opção de CARDAPIO
void displayOpcoesDisp(){

}

// funcao para fazer o cardápio
void makeCardapio(){

}



// Inicializacao do programa
int main (void)
{
  //Definindo variaveis e constantes
  int i, choice;
  struct cardapio cdpo;

  do {
	printf("\n");
	printf("\t\t\t  ================================\n");
	printf("\t\t\t     CARDAPIO\n");
	printf("\t\t\t  ================================");

	printf("\n\nPress:");
	printf("\n 1.) INSERIR OPCOES.");
	printf("\n 2.) EDITAR OPÇÃO");
	printf("\n 3.) DELETAR OPÇÃO");
	printf("\n 4.) MOSTRAR OPÇÕES DISPONIVEIS");
	printf("\n 5.) MOSTRAR CARDAPIO");
	printf("\n 6.) GERAR UM CARDAPIO");
	printf("\n 7.) SAIR DO PROGRAMA.");
	printf("\nESCOLHA--> ");
	scanf("%d", &choice);
	     switch(choice){
        case 1 : //ADICIONA UMA OPCAO DO CARDAPIO
              addOpcao();
              break;
        case 2: //EDITA UMA OPCAO DO CARDAPIO
		    	    editOpcao();
				      break;
        case 3: //DELETAR UMA OPÇAO
              deleteOpcao();
              break;
        case 4: //MOSTRAR OPCOES DISPONIVEIS
              displayOpcoesDisp();
              break;
       	case 5: //MOSTRAR O CARDAPIO DA SEMANA
       	      showCardapio();
		          break;
	   	  case  6: // CRIAR O CARDAPIO.
	   		      makeCardapio();
		 	        break;
		    case 7: //SAIR DO SWITCH CASE
		 	        saida(1);
			        break;
		    default :
                printf("VOCE NAO ESCOLHEU UMA OPCAO VALIDA");
            break;
      }
    }while(choice!=7);
      printf("Thankyou for using this program");

}
