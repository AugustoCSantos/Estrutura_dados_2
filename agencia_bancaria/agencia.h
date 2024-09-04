#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Agencia{
    int codigo;
    char nome[50];
    char gerente[50];
}Agencia;

void imprime(Agencia *ag);

Agencia* agencia(int codigo, char* nome, char* gerente);

void salva(Agencia *ag, FILE *out);

Agencia *le(FILE *in)

int tamanho();

#endif