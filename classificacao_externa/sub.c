#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MEM_SIZE 6 //para os registros

typedef struct Freezer{
    int valor;
    bool congelado;
}Freezer;

void gera_arquivo(FILE *out);
void le_arquivo(FILE *in); //debug
Freezer** inicia_memoria(int *ini);
void descongela(Freezer **F);
int menor_valor_ncongelado(Freezer** F);
void selecao(FILE *in);

int main(){
    FILE *sequenciaReg = fopen("registros.dat", "w+b");

    if(sequenciaReg == NULL){
        printf("Erro ao gerar arquivo\n");
        exit(1);
    }

    gera_arquivo(sequenciaReg);
    rewind(sequenciaReg);
    
    selecao(sequenciaReg);
    fclose(sequenciaReg);

    return 0;
}

void gera_arquivo(FILE *out){
    int reg[23] = {30, 14, 15, 75, 32, 6, 5, 81, 48, 41, 87, 18, 
                    56, 20, 26, 4, 21, 65, 22, 49, 11, 16, 8};
    
    for(int i = 0; i < 23; i++){
        fwrite(&reg[i], sizeof(int), 1, out);
    }
}

void le_arquivo(FILE *in){
    int aux;

    while(fread(&aux, sizeof(int), 1, in)){
        printf("%d ", aux);
    }
}

Freezer** inicia_memoria(int *ini){
    //Aloca espaço para a memória
    //inicializa cada posição da memória com os valores passados no array a 
    //e define o estado congelado como false.
    Freezer **F = (Freezer**)malloc(sizeof(Freezer*) * MEM_SIZE);

    for(int i = 0; i < MEM_SIZE; i++){
        F[i] = (Freezer*)malloc(sizeof(Freezer));
        F[i]->valor = ini[i];
        F[i]->congelado = false;
    }

    return F;
}

void descongela(Freezer **F){
    for(int i = 0; i < MEM_SIZE; i++){
        F[i]->congelado = false;
    }
}

int menor_valor_ncongelado(Freezer** F){
    int pos = -1;
    int menor = 10000;

    //Percorre a memória e encontra o menor valor que não está "congelado".
    //Retorna a posição desse valor. Se todos os valores estiverem congelados, retorna -1.

    for(int i = 0; i < MEM_SIZE; i++){
        if(!(F[i]->congelado) && (F[i]->valor < menor)){
            menor = F[i]->valor;
            pos = i;
        }
    }

    return pos;
}

void selecao(FILE *in){
    Freezer **F;
    int aux[MEM_SIZE];
    int part = 0;

    fread(aux, sizeof(int), MEM_SIZE, in);
    F = inicia_memoria(aux);

    int posicao, novo;
    bool terminou = false;

    while (1) {

        posicao = menor_valor_ncongelado(F);
        if (posicao == -1) {
            printf("\nNova Particao\n");
            descongela(F);
            continue;
        } else {
            if (fread(&novo, sizeof(int), 1, in) <= 0) {
                break;
            }
            
            printf("%d ", F[posicao]->valor);
            if (novo < F[posicao]->valor) {
                F[posicao]->valor = novo;
                F[posicao]->congelado = true;
            } else {
                F[posicao]->valor = novo;
            }
        }
    }

    // Imprimir o último valor
    while ((posicao = menor_valor_ncongelado(F)) != -1) {
        printf("%d ", F[posicao]->valor);
        F[posicao]->congelado = true;
    }
}