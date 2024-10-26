#include "funcsGerais.c"

typedef struct{
  char *name;
  char *cpf;
  char *cont_tel;
  char *email;
} Cliente;

#define esc 27

void adiciona_cliente();
void remove_cliente(char cpf[]);
void ver_clientes();

void adiciona_cliente(){
  Cliente cliente;
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
  printf("\n\t |        ADICIONANDO CLIENTE        |");
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
}

void gerenciamentoClientes(){
  bool menu_op = true;
  int opt_menu; 
  do{
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
  printf("\n\t |        GERENCIANDO CLIENTES       |`\n");
  printf("\n\t | [1] - Adicionar cliente           |");
  printf("\n\t | [2] - Apagar clientes             |");
  printf("\n\t | [3] - Ver clientes                |");
  printf("\n\t | [ESC]- Voltar                     |");
  printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
  opt_menu = getch();

  switch(opt_menu){
    case 1:
    system("cls");
    adiciona_cliente();
    system("cls");
    break;
    case 2:
    system("cls");
//    remove_cliente();
    system("cls");
    break;
    case 3:
    system("cls");
//    ver_clientes();
    system("cls");
    case esc:
    system("cls");
    menu_op = false;
    break;
    default:
    system("cls");
    printf("digite uma opcao valida!");
    system("cls");
    break;
  }
  } while(menu_op);
}
