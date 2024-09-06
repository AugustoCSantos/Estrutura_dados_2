#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeC(Conta *cont){
    printf("-----------------------------------");
    printf("\nCodigo da Conta: ");
    printf("%d", cont->codigo);
    printf("\nCodigo da Agencia: ");
    printf("%d", cont->codAgencia);
    printf("\nSaldo: ");
    printf("%2.lf", cont->saldo);
    printf("\n-----------------------------------\n");
}

Conta* conta(int codigo, int codAgencia, double saldo){
    Conta *cont = (Conta *) malloc(sizeof(Conta));

    if(cont) memset(cont, 0, sizeof(Conta));
    cont->codigo = codigo;
    cont->codAgencia = codAgencia;
    cont->saldo = saldo;

    return cont;
}

void salvaC(Conta *cont, FILE *out){
    fwrite(&cont->codigo, sizeof(int), 1, out);
    fwrite(&cont->codAgencia, sizeof(int), 1, out);
    fwrite(&cont->saldo, sizeof(double), 1, out);
}

Conta *leC(FILE *in){
    Conta *cont = (Conta *) malloc(sizeof(Conta));

    if(0 >= fread(&cont->codigo, sizeof(int), 1, in)){
        free(cont);
        return NULL;
    }
    fread(&cont->codAgencia, sizeof(int), 1, in);
    fread(&cont->saldo, sizeof(double), 1, in);

    return cont;
}

/*int tamanho(){
    return sizeof(int)
            + sizeof(int)
            + sizeof(double);
}*/