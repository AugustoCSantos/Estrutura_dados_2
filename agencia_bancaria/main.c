#include "conta.h"
#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//area da agencia
void le_agencia(FILE *in) {
    printf("\n\nLendo agencias do arquivo...\n\n");
    rewind(in);
    Agencia *a;
    while ((a = le(in)) != NULL) {
        imprime(a);
        free(a);
    }
}

void cadastra_agencia(FILE *out){
    int codigo;
    char nome[50];
    char gerente[50];

    printf("\nCadastrando uma nova agência...\n");
    printf("Digite o ID da agência: ");
    scanf("%d", &codigo);
    printf("Digite o nome da agência: ");
    scanf("%s", nome);
    printf("Digite o nome do gerente: ");
    scanf("%s", gerente);

    Agencia *nova_agencia = agencia(codigo, nome, gerente);
    salva(nova_agencia, out);
    free(nova_agencia);

    printf("Agência cadastrada com sucesso!\n");
}

//area da conta
void le_conta(FILE *in) {
    printf("\n\nLendo contas do arquivo...\n\n");

    rewind(in);
    Conta *c;
    while ((c = le(in)) != NULL) {
        imprimeC(c);
        free(c);
    }
}

void cadastra_conta(FILE *out){
    int codigo, codAgencia;
    double saldo;

    printf("\nCadastrando uma nova conta...\n");
    printf("Digite o número da conta: ");
    scanf("%d", &codigo);
    printf("Digite o número da agência: ");
    scanf("%d", &codAgencia);
    printf("Digite o saldo inicial: ");
    scanf("%.2lf", &saldo);

    Conta *nova_conta = conta(codigo, codAgencia, saldo);
    salva(nova_conta, out);
    free(nova_conta);

    printf("Conta cadastrada com sucesso!\n");
}

int main(){
    FILE *agencia_file = fopen("agencias.dat", "a+b"); //a+b abre o arquivo para leitura e escrita,
    FILE *conta_file = fopen("contas.dat", "a+b");    // e cria um novo se não existir

    if (agencia_file == NULL || conta_file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int opcao;

    do {
        printf("\n\n==== Menu ====\n");
        printf("1. Cadastrar nova agência\n");
        printf("2. Cadastrar nova conta\n");
        printf("3. Ler agências\n");
        printf("4. Ler contas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastra_agencia(agencia_file);
                break;
            case 2:
                cadastra_conta(conta_file);
                break;
            case 3:
                le_agencia(agencia_file);
                break;
            case 4:
                le_conta(conta_file);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    fclose(agencia_file);
    fclose(conta_file);

    return 0;
}