#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 6 //para os registros

void escreve(FILE *out);
void le(FILE *in);
void selecao();

int main(){
    FILE *sequenciaReg = fopen("registros.dat", "w+b"); //arquivo desordenado.

    if(sequenciaReg == NULL){
        printf("Error ao abrir o arquivo.\n");
    }

    escreve(sequenciaReg);
    rewind(sequenciaReg);
    //le(sequenciaReg); //usei pra debugar se havia escrito no arquivo.

    FILE *saida = fopen("saidaOrdenada.dat", "w+b"); //saida com o arquivo ordenado.

    if (saida == NULL){
        printf("Error ao abrir o arquivo.\n");
        fclose(sequenciaReg);
        return 1;
    }

    fclose(sequenciaReg);

    return 0;
}

void escreve(FILE *out){
    int reg[23] = {30, 14, 15, 75, 32, 6, 5, 81, 48, 41, 87, 18, 
                    56, 20, 26, 4, 21, 65, 22, 49, 11, 16, 8};

    for(int i = 0; i < 23; i++){
        fwrite(&reg[i], sizeof(int), 1, out);
    }
}

void le(FILE *in){
    int auxReg;

    rewind(in);

    while(fread(&auxReg, sizeof(int), 1, in)){
        printf("%d\n", auxReg);
    }
}