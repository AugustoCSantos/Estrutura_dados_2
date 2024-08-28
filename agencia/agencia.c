#include "agencia.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void imprime(Agencia *ag){
    printf("------------------------");
    printf("\nCodigo da Agencia: ");
    printf("%d", ag->codAgencia);
    printf("\nNome da Agencia: ");
    printf("%s", ag->nome);
    printf("\nNome do gerente: ");
    printf("%s", ag->gerente);
    printf("------------------------");
}

Agencia *agencia(int codAgencia, char *nome, char *gerente){
    Agencia *agencia = (Agencia *) malloc(sizeof(Agencia));

    if(agencia) memset(agencia, 0, sizeof(Agencia));

    agencia->codAgencia = codAgencia;
    strcpy(agencia->nome, nome);
    strcpy(agencia->gerente, gerente);

    return agencia;
}

void salva(Agencia *ag, FILE *out){
    fwrite(&ag->codAgencia, sizeof(int), 1, out);
    fwrite(ag->nome, sizeof(char), sizeof(ag->nome), out);
    fwrite(ag->gerente, sizeof(char), sizeof(ag->gerente), out);
}

Agencia *le(FILE *in){
    Agencia *ag = (Agencia *) malloc(sizeof(Agencia));

    if (0 >= fread(&ag->codAgencia, sizeof(int), 1, in)){
        free(ag);
        return NULL;
    }

    fread(ag->nome, sizeof(char), sizeof(ag->nome), in);
    fread(ag->gerente, sizeof(char), sizeof(ag->gerente), in);

    return ag;   
}

void leTodasAg(FILE *in){
    Agencia *a;

    while((a = le(in)) != NULL) {
        printf("\n");
        imprime(a);
        free(a);
    }
}

int tamanho(){
    return sizeof(int) //codigo conta
            + sizeof(int) //codigo agencia
            + sizeof(double); //saldo
}