#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Agencia{
    int codAgencia;
    char nome[50];
    char gerente[50];
} Agencia;

// Imprime.
void imprime(Agencia *ag);

// Cria agencia.
Agencia *agencia(int codAgencia, char *nome, char *gerente);

// Salva agencia.
void salva(Agencia *ag, FILE *out);

// Le uma agencia.
Agencia *le(FILE *in);

void leTodasAg(FILE *in);

// Retorna tamanho da agencia em bytes.
int tamanho();

#endif