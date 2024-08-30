#include "agencia.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1 
#define FALSE 0

int main() {

    int terminou = TRUE;
    do{
        printf("------------------------");
        printf("\n1 - Cadastrar agencia ");
        printf("\n2 - Ler agencia ");
        printf("\n3 - Mostrar agencias ");
        printf("\n4 - Cadastrar conta ");
        printf("\n5 - Ler conta ");
        printf("\n6 - Mostrar contas ");
        printf("\n7 - Sair \n");
        printf("------------------------");

        int op;
        printf("\nOperação: ");
	    scanf("%d", &op);

	    switch(op){
            case 1:
                break;
            case 2:
                break;
                
            case 3:
                FILE *in;
                in = fopen("agencia.dat", "rb");

                printf("Listagem de agências:\n");
                rewind(in);

                le(in);
            
                break;
    
            case 4:
                break;
            case 5:
                break;
            case 6:
                FILE *in;
                in = fopen("conta.dat", "rb");

                printf("Listagem de contas:\n");
                rewind(in);

                le(in);
                break;

            case 7:
                terminou = FALSE;
                break;
        } 
    }while(terminou);
    

    return 0;
}