#include "funcsGerais.c"

void menu_pedidos();
void fazerPedido();

void fazerPedido(){

    pintf("escolha ")

}


void menu_pedidos(){
    bool menu_op = true;
    int opt_menu, cicloaux = 0;
    char pe_carne;

    printf(" - - - - - - -");
    printf("|  [1] Ver cardápio   |");
    printf("|  [2] Realizar pedido  |");
    printf("|  [3] Listar pedidos  |");
    printf("|  [esc] Sair  |")
    opt_menu = getch();

    switch (opt_menu)
    {
        case '1':
            system("cls");
            ver_cardapio();   
            printf("\n\n\t[digite qualquer tecla para sair]"); 
            getch();
            system("cls");
        break;
        case '2':
            do{
                printf("\n\t | Pedido com hambúrguer?  |");
			    printf("\n\t | Se SIM pressione s  |");
				printf("\n\t | Se NÃO pressione n  |");
                pe_carne = getch();
                if(pe_carne == 's' or pe_carne == 'S' or pe_carne == 'n' or pe_carne == 'N'){cicloaux = 0;}
            }while(cicloaux == 1);
        break;

        default:
            break;
    }
}