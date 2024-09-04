#ifndef AGENCIA_H
#define AGENCIA_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Agencia{
    int codigo;
    char nome[50];
    char gerente[50];
}Agencia;

//Criacao: Essa função aloca memoria para uma nova estrutura Agencia e inicializa seus membros com os valores passados como parametros.
Agencia* nova_agencia(int codigo, char* nome, char* gerente);

//Escreve os dados da agencia em um arquivo binario. Isso permite que a informacao seja salva e carregada posteriormente.
void salva_agencia(Agencia* agencia, FILE* archive);

//Le os dados de uma agencia a partir de um arquivo binario e cria uma nova estrutura Agencia com essas informacoes.
Agencia* ler_agencia(FILE* archive);

//Exibe na tela os dados da agencia de forma formatada.
void imprime_agencia(Agencia* agencia);

//Procura uma agencia especifica no arquivo, identificada pelo seu codigo.
Agencia* consulta_agencia(int num_agencia, FILE* archive);

#endif