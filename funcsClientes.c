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
  char ativo[3];
} Usuario;

#define esc 27
#define NOMEARQUIVO "cadastros.txt"

/// prototipos
void adiciona_cliente();
void remove_cliente(char cpf[]);
void ver_clientes();
void busca_cliente(char *cpf_cliente);
void ordenarCPF(Usuario *listaCliente, int n);
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

void busca_cliente(char *cpf_cliente){

  FILE *fp = fopen(NOMEARQUIVO, "r");
  if (fp == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return;
  }

  char linha[200];
  char *nome, *cpf, *email, *tel, *ativo;

  printf("\n\tBuscando usuario com CPF: %s\n", cpf_cliente);
  sleep(1);
  printf("\n\t...");
  sleep(1);
  printf("\n\t...");
  sleep(1);
  printf("\n\t...");
  sleep(1);
  system("cls");

  while (fgets(linha, sizeof(linha), fp)) {
    // Remover a nova linha, se houver
    linha[strcspn(linha, "\n")] = '\0';

    nome  = strtok(linha, ",");
    cpf   = strtok(NULL, ",");
    email = strtok(NULL, ",");
    tel   = strtok(NULL, ",");
    ativo = strtok(NULL, ",");

    if (strcmp(cpf, cpf_cliente) == 0) {
      printf("\n\t  ___________________________________ ");
      printf("\n\t |         Usuario encontrado:       |");
      printf("\n\t |___________________________________|");
      printf("\n\t |Nome:      %s", nome);
      printf("\n\t |CPF:       %s", cpf);
      printf("\n\t |Email:     %s", email);
      printf("\n\t |Telefone:  %s", tel);
      printf("\n\t |Ativo:     %s", ativo);
      
      printf("\n\t  ------------------------------------\n\n");
      fclose(fp);
      return;
    }
  }

  printf("\n\t  ------------------------------------ ");
  printf("\n\t |       USUARIO NAO ENCONTRADO       |");
  printf("\n\t |____________________________________|");
  fclose(fp);

}

void ordenarCPF(Usuario *listaCliente, int n) {
  int i, j;
  Usuario temp;

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (strcmp(listaCliente[j].cpf, listaCliente[j + 1].cpf) > 0) {
        // Trocar os CPFs se estiverem na ordem errada
        temp = listaCliente[j];
        listaCliente[j] = listaCliente[j + 1];
        listaCliente[j + 1] = temp;
      }
    }
  }
}

void adiciona_cliente(){
  Cliente cliente;
  FILE *cadArquivo = fopen(NOMEARQUIVO, "a+");

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

  fprintf(cadArquivo, "%s,%s,%s,%s,Sim\n", cliente.name, cliente.cpf, cliente.email, cliente.cont_tel);
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

void ver_clientes() {
  FILE *fp = fopen(NOMEARQUIVO, "r");
  if (fp == NULL) {
    fprintf(stderr, "ERRO AO ABRIR O ARQUIVO!!.\n");
    exit(1);
  }

  Usuario *users = NULL;
  int user_count = 0; // Contador de usuários
  char string[200];

  printf("\n\t  ----------------------------------------------- ");
  printf("\n\t |              *lista de clientes*              |");
  printf("\n\t | _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n\n");

  printf("\t  ___________________________________________");
  while (fgets(string, sizeof(string), fp) != NULL) {
    // Remove o caractere de nova linha se presente
    string[strcspn(string, "\n")] = '\0';

    Usuario *temp = realloc(users, (user_count + 1) * sizeof(Usuario));

    if (temp == NULL) {
      fprintf(stderr, "Erro: não foi possível alocar a memória.\n");
      free(users);
      fclose(fp);
      exit(1);
    }
    users = temp;

    // Tokenizar os dados
    char *name  = strtok(string, ",");
    char *cpf   = strtok(NULL, ",");
    char *mail  = strtok(NULL, ",");
    char *tel   = strtok(NULL, ",");
    char *ativo = strtok(NULL, ",");

    // Exibir informações do cliente
    printf("\n\t | Nome:      %s", name);
    printf("\n\t | Cpf:       %s", cpf);
    printf("\n\t | Email:     %s", mail);
    printf("\n\t | Tel:       %s", tel);
    printf("\n\t | Ativo:     %s", ativo);
    printf("\n\t |___________________________________________");

    // Armazenar dados no array
    strcpy(users[user_count].nome, name);
    strcpy(users[user_count].cpf, cpf);
    strcpy(users[user_count].mail, mail);
    strcpy(users[user_count].tel, tel);
    strcpy(users[user_count].ativo, ativo);
    user_count++;
  }

  fclose(fp);

  int menu_opt;
  bool menu_rodando = true;

  char cpf_buscado[15];

  do{
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    printf("\n\t |            GERENCIANDO CLIENTES           |");
    printf("\n\t |-------------------------------------------|");
    printf("\n\t |  [1]  - Buscar cliente (por CPF)          |");
    printf("\n\t |  [2]  - Ordenar lista (por CPF)           |");
    printf("\n\t | [ESC] - Voltar                            |");
    printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    menu_opt = getch();
  
    switch (menu_opt) {
      case '1':
        system("cls"); 
        printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
        printf("\n\t |        CPF DO USUARIO A SER BUSCADO       |");
        printf("\n\t |-------------------------------------------|");
        printf("\n\t | "); scanf("%s", cpf_buscado);
        busca_cliente(cpf_buscado);
      break;
      case '2':
        system("cls");
        ordenarCPF(users, user_count);
        int i;

        printf("\n\t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
        printf("\n\t |             USUARIOS ORDENADOS            |");
        printf("\n\t |-------------------------------------------|");

        for(i = 0; i < user_count; i++){
          printf("\n\t | Nome:      %s", users[i].nome);
          printf("\n\t | Cpf:       %s", users[i].cpf);
          printf("\n\t | E-mail:    %s", users[i].mail);
          printf("\n\t | Tel:       %s", users[i].tel);
          printf("\n\t | Ativo:     %s", users[i].ativo);
          printf("\n\t |------------------------------------------");
        }
      break;
      case esc:
        menu_rodando = false;
      break;
      default:
        system("cls");
        printf("\nDigite uma opcao valida.\n");
        printf("%d", menu_opt);
      break;
    }
  }while(menu_rodando);

  free(users);
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
