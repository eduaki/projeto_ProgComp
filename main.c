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
  char *nome[30];
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


int main(void){
  char menu_opt;
  bool rodando_menu = true; 

do{
  menu_principal();

  menu_opt = getch();

switch (menu_opt){
  case '1':
    system("cls");
    printf("mostra o cardapio");
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
