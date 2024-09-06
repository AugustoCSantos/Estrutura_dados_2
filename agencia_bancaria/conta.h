#ifndef CONTA_H
#define CONTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Conta {
	int codigo;
	int codAgencia;
	double saldo;
} Conta;

void imprimeC(Conta *cont);

Conta* conta(int codigo, int codAgencia, double saldo);

void salvaC(Conta *cont, FILE *out);

Conta *leC(FILE *in);

int tamanho();

#endif