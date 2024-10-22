#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#include<stdbool.h>
#include <windows.h>

#define esc 27

typedef struct{
  char *name;
  char *cpf;
  char *cont_tel;
  char *email;
} Cliente;

typedef struct{
  char *nome;
  float preco;
} Prod;


/// funcoes de cliente
void adiciona_cliente(Cliente cliente);
void remove_cliente(char cpf[]);
void ver_clientes();

/// funcoes pedidos
void fazer_pedido(char cpf_cliente[], Prod *lista_prod[], int viagem);
void ver_pedidos();

void fazer_reserva(Cliente cliente, int qtd_pessoas, int dia, int mes, int hora);

void menu_principal();
void ver_cardapio();
void tabela_preco();


void menu_principal(){
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
  printf("\n\t |                                                         |");
  printf("\n\t | [1] - cardapio                                          |");
  printf("\n\t | [2] - Gerenciar clientes                                |");
  printf("\n\t | [3] - Gerenciar pedidos                                 |");
  printf("\n\t | [4] - Fazer reserva                                     |"); 
  printf("\n\t | [ESC]- Voltar                                           |");
  printf("\n\t  ");
}



void ver_cardapio(){
  printf(" \n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n|          *Carnes*            |");
  printf("\n| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|");
  printf("\n|       Picanha Grelhada       |");
  printf("\n|   Mignon na Mostarda e Mel   |");
  printf("\n|        Filet Argentino       |");
  printf("\n|     Fraldinha na Mostarda    |");
  printf("\n|      Maminha com Queijo      |");
  printf("\n|           Short Rib          |");
  printf("\n|            Coração           |");
  printf("\n|        Costela de Porco      |");
  printf(" \n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n");
  printf("\n  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n|        *Massas/Risoto*       |");
  printf("\n| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|");
  printf("\n|         Nhoque Frito         |");
  printf("\n|    Lasanha Quatro Queijos    |");
  printf("\n|     Conchiglione de Figo     |");
  printf("\n|         Fettuccini           |");
  printf("\n|    Banana com Chocolate      |");
  printf("\n|      Nhoque Dois Amores      |");
  printf("\n|      Risoto de Palmito       |");
  printf("\n|      Risoto de Camarão       |");
  printf(" \n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n");
  printf(" \n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n|        *Sobremesas*          |");
  printf("\n| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|");
  printf("\n|            Tortas            |");
  printf("\n|            Mousses           |");
  printf("\n|             Pavês            |");
  printf(" \n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  \n");
  printf("obs: confira a opção disponível no dia");
}



void tabela_preco(){
  printf("\n  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n|             *Tabela de Preços*              |");
  printf("\n| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n| De terça a sexta.......R$ 149,90/por pessoa |");
  printf("\n| Sábado e Domingo.......R$ 159,90/por pessoa |");
  printf("\n _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
}


int main(void){
  char menu_opt;
  bool rodando_menu = true; 

do{
  menu_principal();

  menu_opt = getch();

switch (menu_opt){
  case '1':
    system("cls");
    ver_cardapio();
    tabela_preco();
    system("cls");
    break;
  case '2':
    system("cls");
    printf("abre o menu de gerencimento de clientes");
    system("cls");
  break;
  case '3':
    system("cls");
    printf("abre o menu de gerenciamente de pedidos");
    system("cls");
  break;
  case '4':
    system("cls");
    printf("abre o menu de gerenciamento de reservas");
    system("cls");
  break;
  case esc:
    system("cls");
    rodando_menu = false;
    system("cls");
  break;
  default:
    system("cls");
    printf("digite uma opcao valida");
    system("cls");
  break;
}
  } while(rodando_menu == true);
  return 0;
}
