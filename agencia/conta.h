#ifndef CONTA_H
#define CONTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Conta{
    int codConta;
    int codAgencia;
    double saldo;
} Conta;

// Imprime.
void imprimeConta(Conta *conta);

// Cria conta.
Conta *conta(int codConta, int codAgencia, double saldo);

// Salva conta.
void salvaConta(Conta *conta, FILE *out);

// Le uma conta.
Conta *leConta(FILE *in);

void leTodasContas(FILE *in);

// Retorna tamanho da conta em bytes.
int tamanho();

#endif