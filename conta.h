#ifndef CONTA_H
#define CONTA_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Conta {
	int codigo;
	int codAgencia;
	double saldo;
} Conta;

Conta* novaConta(int codigo, int codAgencia, double saldo);
void salvarConta(Conta* conta, FILE* archive);
Conta* lerConta(FILE* archive);
void imprimeConta(Conta* conta);
Conta* consultarConta(int numConta, FILE* archive);

#endif