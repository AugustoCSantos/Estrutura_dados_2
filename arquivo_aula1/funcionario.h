#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario {
    int cod;
    char nome[50];
    char cpf[15];             //estrutura funcionario.
    char data_nascimento[11];
    double salario;
} Funcionario;

// Imprime funcionario.
void imprime(Funcionario *func);

// Cria funcionario.
Funcionario *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

// Salva funcionario.
void salva(Funcionario *func, FILE *out);

// Le um funcionario.
Funcionario *le(FILE *in);

// Retorna tamanho do funcionario em bytes.
int tamanho();

#endif

