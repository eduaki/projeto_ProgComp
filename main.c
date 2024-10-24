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
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
  printf("\n\t |                                   |");
  printf("\n\t | [1] - cardapio                    |");
  printf("\n\t | [2] - Gerenciar clientes          |");
  printf("\n\t | [3] - Gerenciar pedidos           |");
  printf("\n\t | [4] - Fazer reserva               |"); 
  printf("\n\t | [ESC]- Voltar                     |");
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
}



void ver_cardapio(){
  printf("\n\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n\t |           *Carnes*            |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n\t |   Picanha Grelhada            |");
  printf("\n\t |   Mignon na Mostarda e Mel    |");
  printf("\n\t |   Filet Argentino             |");
  printf("\n\t |   Fraldinha na Mostarda       |");
  printf("\n\t |   Maminha com Queijo          |");
  printf("\n\t |   Short Rib                   |");
  printf("\n\t |   Coracao                     |");
  printf("\n\t |   Costela de Porco            |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ | ");
  printf("\n\t");
  printf("\n\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n\t |        *Massas/Risotos*       |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n\t |   Nhoque Frito                |");
  printf("\n\t |   Lasanha Quatro Queijos      |");
  printf("\n\t |   Conchiglione de Figo        |");
  printf("\n\t |   Fettuccini                  |");
  printf("\n\t |   Banana com Chocolate        |");
  printf("\n\t |   Nhoque Dois Amores          |");
  printf("\n\t |   Risoto de Palmito           |");
  printf("\n\t |   Risoto de Camarao           |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n\t");
  printf("\n\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n\t |         *Sobremesas*          |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n\t |   Tortas                      |");
  printf("\n\t |   Mousses                     |");
  printf("\n\t |   Paves                       |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n\n\tobs: confira a opcao disponivel no dia");
}



void tabela_preco(){
  printf("\n\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  ");
  printf("\n\t |             *Tabela de Precos*              |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
  printf("\n\t | De terca a sexta.......R$ 149,90/por pessoa |");
  printf("\n\t | Sabado e Domingo.......R$ 159,90/por pessoa |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |");
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
    printf("\n\n\t[digite qualquer tecla para sair]");
    getch(); /// entrada do teclado, so pra sair do cardápio
    system("cls"); /// limpa o console apos a execução
    break;
  case '2':
    system("cls");
    printf("abre o menu de gerencimento de clientes");
    if(getch()) system("exit");
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

  system("exit");
  return 0;
}
