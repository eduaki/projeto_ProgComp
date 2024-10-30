#include "funcsGerais.c"
// #include "testleitura.c" /// arquivo de testes

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
  bool cadFim;
  FILE *cadArquivo = fopen("cadastros.txt", "ab");

  cliente.name = (char *) malloc(50);
  cliente.cpf = (char *) malloc(15);
  cliente.email = (char *) malloc(100);
  cliente.cont_tel = (char *) malloc(13);

if(
  cliente.name == NULL ||
  cliente.cpf == NULL ||
  cliente.email == NULL ||
  cliente.cont_tel == NULL
){
  system("cls");
printf("ERRO NA ALOCACAO DE MEMORIA!!");
exit(1);
}

  if(cadArquivo == NULL){
    printf("ERRO AO ABRIR ARQUIVO");
    exit(1);
  }

    system("cls");
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    printf("\n\t |        ADICIONANDO CLIENTE        |");
    printf("\n\t |-----------------------------------|");
    printf("\n\t | Nome: "); scanf("%[^\n]", cliente.name);
    printf("\t | CPF: "); scanf("%s", cliente.cpf);
    printf("\t | email: "); scanf("%s", cliente.email);
    printf("\t | telefone: "); scanf("%s", cliente.cont_tel);

    fprintf(cadArquivo, "%s, %s, %s, %s\n", cliente.name, cliente.cpf, cliente.email, cliente.cont_tel);
    printf("\t\tdados salvos com sucesso!\n\t\t[aguarde um momento]");
    sleep(3);

  if(fclose(cadArquivo) != 0){
    printf("ERRO AO FECHAR ARQUIVO");
    exit(1);
  }
}

void gerenciamentoClientes(){
  bool menu_op = true; /// define que o menu esta aberto desde o comeco da execucao da funcao
  int opt_menu; 
  do{
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    printf("\n\t |        GERENCIANDO CLIENTES       |");
    printf("\n\t |-----------------------------------|");
    printf("\n\t | [1] - Adicionar cliente           |");
    printf("\n\t | [2] - Apagar clientes             |");
    printf("\n\t | [3] - Ver clientes                |");
    printf("\n\t | [ESC]- Voltar                     |");
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    opt_menu = getch();

      int test;
    switch(opt_menu){
      case '1':
      system("cls");
      adiciona_cliente();
      system("cls");
      break;
      case '2':
      system("cls");
  //    remove_cliente();
      system("cls");
      break;
      case '3':
      system("cls");
      // leituradados(); essa funcao esta em testes 
      getch();
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
