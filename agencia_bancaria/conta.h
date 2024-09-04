#ifndef CONTA_H
#define CONTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Conta {
	int codigo;
	int codAgencia;
	double saldo;
} Conta;

void imprime(Conta *cont);

Conta* conta(int codigo, int codAgencia, double saldo);

void salva(Conta *cont, FILE *out);

Conta *le(FILE *in);

int tamanho();

#endif