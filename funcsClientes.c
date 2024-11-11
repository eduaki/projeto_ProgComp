#include "funcsGerais.c"

typedef struct{
  char *name;
  char *cpf;
  char *cont_tel;
  char *email;
} Cliente;

typedef struct { 
  char nome[70];
  char cpf[15];
  char mail[200];
  char tel[13];
} Usuario;

#define esc 27
#define NOMEAQUIVO "cadastros.txt"

/// prototipos
void adiciona_cliente();
void remove_cliente(char cpf[]);
void ver_clientes();
/// fim prototipos

// funcao que verifica se o cpf é valido
int validarcpf(char cpf[15]) {
  long long int cpf_int;
  int i, j, soma, resto, digito1, digito2;
  int peso1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
  int peso2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
  
  /// verifica se tem um caracter nao numerico no cpf
  for (i = 0; cpf[i] != '\0'; i++) {
    if (!isdigit(cpf[i])) {
      return 1; // cpf invalido
    }
  }

  // Converte o CPF para um número inteiro
  cpf_int = atoll(cpf);

  if (cpf_int <= 0 || cpf_int >= 100000000000) {
    return 1; // cpf invalido
  } 

  // Verifica se o CPF possui 11 dígitos
  if (cpf_int < 100000000 || cpf_int > 99999999999) {
      return 1; // CPF inválido
  }

  // Calcula o primeiro dígito verificador
  soma = 0;
  for (i = 0; i < 9; i++) {
      soma += (cpf_int % 10) * peso1[i];
      cpf_int /= 10;
  }
  resto = soma % 11;
  if (resto < 2) {
      digito1 = 0;
  } else {
      digito1 = 11 - resto;
  }

  // Calcula o segundo dígito verificador
  soma = 0;
  for (i = 0; i < 10; i++) {
      soma += (cpf_int % 10) * peso2[i];
      cpf_int /= 10;
  }
  resto = soma % 11;
  if (resto < 2) {
      digito2 = 0;
  } else {
      digito2 = 11 - resto;
  }
  // Reconstrói o CPF original para comparação
  int cpf_calculado = digito2 * 10 + digito1;

  // Compara os dígitos calculados com os dígitos do CPF original
  if (cpf_int == cpf_calculado) {
    return 1; // CPF inválido
  } else {
    return 0; // CPF válido
  }
}
void adiciona_cliente(){

  Cliente cliente;
  FILE *cadArquivo = fopen(NOMEAQUIVO, "ab");

  cliente.name = (char *) malloc(50);
  cliente.cpf = (char *) malloc(15);
  cliente.email = (char *) malloc(100);
  cliente.cont_tel = (char *) malloc(13);

  if(
    cliente.name     == NULL ||
    cliente.cpf      == NULL ||
    cliente.email    == NULL ||
    cliente.cont_tel == NULL
  ){
    system("cls");
    printf("ERRO NA ALOCACAO DE MEMORIA!!");
    exit(1);
  }

  if(cadArquivo == NULL){
    printf("ERRO AO ABRIR ARQUIVO!!");
    exit(1);
  }

  char nome[70];
  char cpf[15];
  char mail[200];
  char tel[15];

  system("cls");
  printf("\n\t  ----------------------------------- ");
  printf("\n\t |        ADICIONANDO CLIENTE        |");
  printf("\n\t |___________________________________|");
  fflush(stdin);
  printf("\n\t | Nome completo: "); scanf("%[^\n]", nome);
  fflush(stdin);
  printf("\t | CPF: "); scanf("%s", cpf);
  fflush(stdin);
  printf("\t | E-mail: "); scanf("%s", mail);
  fflush(stdin);
  printf("\t | Telefone: "); scanf("%s", tel);
  fflush(stdin);
  printf("\t |____________________________________\n");

  strcpy(cliente.name, nome);
  strcpy(cliente.cpf, cpf);
  strcpy(cliente.email, mail);
  strcpy(cliente.cont_tel, tel);

  if(validarcpf(cpf)){
    printf("\n\t[CPF invalido!! Tente criar o usuario novamente...]");
    sleep(2);
    system("cls");
    return;
  }

  fprintf(cadArquivo, "%s, %s, %s, %s\n", cliente.name, cliente.cpf, cliente.email, cliente.cont_tel);
  fflush(cadArquivo);
  printf("\t\tdados salvos com sucesso!\n\t\t[aguarde um momento]");
  sleep(2);

  if(fclose(cadArquivo) != 0){
    printf("ERRO AO FECHAR ARQUIVO");
    exit(1);
  }

  /// limpra a memoria alocada na criacao do usuario
  free(cliente.name);
  free(cliente.cpf);
  free(cliente.email);
  free(cliente.cont_tel);
}

void ver_clientes(){
  FILE *fp = fopen(NOMEAQUIVO, "r");
  if (fp == NULL) {
    fprintf(stderr, "ERRO AO ABRIR O ARQUIVO!!.\n");
    exit(1);
  }

  Usuario *users = NULL;
  int user_count = 0; // variavel controle de usuarios para alocacao de memoria
  char string[200];

  users = (Usuario *) malloc((user_count + 1) * sizeof(Usuario));

  printf("\n\t  ----------------------------------------------- ");
  printf("\n\t |              *lista de clientes*              |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n\n");

  printf("\t  ___________________________________________");
  while (fgets(string, sizeof(string), fp) != NULL) {
    // Remove o caractere de nova linha se presente
    string[strcspn(string, "\n")] = '\0';

    users = realloc(users, (user_count + 1) * sizeof(Usuario));
    if (users == NULL) {
      fprintf(stderr, "Erro: nao foi possivel alocar a memoria.\n");
      fclose(fp);
      exit(1);
    }

    char *name;
    char *cpf;
    char *mail;
    char *tel;

    name = (char *) malloc(70);
    cpf = (char *) malloc(15);
    mail = (char *) malloc(200);
    tel = (char *) malloc(13);

    name = strtok(string, ",");
    cpf = strtok(NULL, ",");
    mail = strtok(NULL, ",");
    tel = strtok(NULL, ",");
    printf("\n\t | nome:   %s", name);
    printf("\n\t | cpf:    %s", cpf);
    printf("\n\t | email:  %s", mail);
    printf("\n\t | tel:    %s", tel);
    printf("\n\t |___________________________________________");


    //// essa parte ainda é um pouco inutil, mas eu vou achar uma utilidade pra ela
    // strcpy(users[user_count].nome, name);
    // strcpy(users[user_count].cpf, cpf);
    // strcpy(users[user_count].mail, mail);
    // strcpy(users[user_count].tel, tel);

    user_count++;
  }

  fclose(fp);
  printf("\n\n\t[Pressione qualquer tecla para sair...]\n");
}

void gerenciamentoClientes(){
  bool menu_op = true; /// define que o menu esta aberto desde o comeco da execucao da funcao
  int opt_menu; 

  do{
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    printf("\n\t |        GERENCIANDO CLIENTES       |");
    printf("\n\t |-----------------------------------|");
    printf("\n\t |  [1]  - Adicionar cliente         |");
    printf("\n\t |  [2]  - Apagar clientes           |");
    printf("\n\t |  [3]  - Ver clientes              |");
    printf("\n\t | [esc] - Voltar                    |");
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    opt_menu = getch();

    switch(opt_menu){
      case '1':
        system("cls");
        adiciona_cliente();
        system("cls");
      break;
      case '2':
        system("cls");
        //remove_cliente();
        system("cls");
      break;
      case '3':
        system("cls");
        ver_clientes();
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
