#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
  char name[50];
  char cpf[15];
  char cont_tel[10];
  char email[50]
} Cliente;

typedef struct{
  char nome[30];
  float preco;
} prod;


/// funcoes de cliente
void adiciona_cliente(Cliente);
void remove_cliente(char cpf[]);
void ver_clientes();

/// funcoes pedidos
void fazer_pedido(char cpf_cliente[], prod *lista_prod[], int viagem);
void ver_pedidos();

void fazer_reserva(Cliente cliente, int qtd_pessoas, int dia, int mes, int hora);

int main(void){

printf('teste');

  return 0;
}