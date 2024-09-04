#include "agencia.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void imprime(Agencia *ag){
    printf("-----------------------------------");
    printf("\nCodigo da Agencia: ");
    printf("%d", ag->codigo);
    printf("\nNome da Agencia: ");
    printf("%s", ag->nome);
    printf("\nNome do Gerente: ");
    printf("%s", ag->gerente);
    printf("-----------------------------------\n");
}

Agencia* agencia(int codigo, char* nome, char* gerente){
    Agencia *ag = (Agencia *) malloc(sizeof(Agencia));

    if(ag) memset(ag, 0, sizeof(Agencia));

    ag->codigo = codigo;
    strcpy(ag->nome, nome);
    strcpy(ag->gerente, gerente);

    return ag;
}

void salva(Agencia *ag, FILE *out){
    fwrite(&ag->codigo, sizeof(int), 1, out);
    fwrite(ag->nome, sizeof(char), sizeof(ag->nome), out);
    fwrite(ag->gerente, sizeof(char), sizeof(ag->gerente), out);
}

Agencia *le(FILE *in){
    Agencia *ag = (Agencia *) malloc(sizeof(Agencia));

    if(0 >= fread(&ag->codigo, sizeof(int), 1, in)){
        free(ag);
        return NULL;
    }
    fread(ag->nome, sizeof(char), sizeof(ag->nome), in);
    fread(ag->gerente, sizeof(char), sizeof(ag->gerente), in);

    return ag;
}

int tamanho(){
    return sizeof(int)
            + sizeof(char) * 50
            + sizeof(char) * 50;
}