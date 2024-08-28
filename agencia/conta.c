#include "conta.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void imprimeConta (Conta *conta){
    printf("------------------------");
    printf("\nCodigo da Conta: ");
    printf("%d", conta->codConta);
    printf("\nCodigo da Agencia: ");
    printf("%d", conta->codAgencia);
    printf("\nSaldo: ");
    printf("%.3lf", conta->saldo);
    printf("------------------------");
}

Conta *conta(int codConta, int codAgencia, double saldo){
    Conta *conta = (Conta *) malloc(sizeof(Conta));

    if(conta) memset(conta, 0, sizeof(Conta));

    conta->codConta;
    conta->codAgencia;
    conta->saldo;

    return conta;
}

void salvaConta(Conta *conta, FILE *out){
    fwrite(&conta->codConta, sizeof(int), 1, out);
    fwrite(&conta->codAgencia, sizeof(int), 1, out);
    fwrite(&conta->saldo, sizeof(double), 1, out);
}

Conta *leConta(FILE *in){
    Conta *conta = (Conta *) malloc(sizeof(Conta));

    if (0 >= fread(&conta->codConta, sizeof(int), 1, in)){
        free(conta);
        return NULL;
    }

    fread(&conta->codAgencia, sizeof(int), 1, in);
    fread(&conta->saldo, sizeof(double), 1, in);
    
    return conta;
}

Conta* consultarConta(int num_conta, FILE* arq) {
	Conta* acc;

	rewind(arq);
    
	while((acc = ler_conta(arq)) != NULL) {
		if(acc->codConta == num_conta) {
			return acc;
		}
	}
	return NULL;
}
