#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 6 //para os registros

void escreve(FILE *out);
void le(FILE *in);
void selecao(FILE *in, FILE *out);
void insereHeap(int heap[], int *n, int valor);
int remover(int heap[], int *n); 

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

    selecao(sequenciaReg, saida);
    rewind(saida);
    le(saida);  //Ler os registros após a seleção por substituição

    fclose(sequenciaReg);
    fclose(saida);

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

void insereHeap(int heap[], int *n, int valor) {
    int i = (*n)++; //Aumenta o tamanho do heap e define a posição do novo valor.

    while (i > 0 && valor < heap[(i - 1) / 2]) {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = valor;
}

int remover(int heap[], int *n) {
    int menor = heap[0];  //O menor valor é sempre o valor do topo (raiz).
    int temp = heap[--(*n)];  //O último valor do heap é movido para o topo.
    int i = 0, filho;

    //Reorganiza o heap "descendo" o valor temporário (temp) até a posição correta.
    while ((filho = 2 * i + 1) < *n) {  //Enquanto o filho esquerdo existir.
        if (filho + 1 < *n && heap[filho + 1] < heap[filho]) {  //Se o filho direito for menor que o esquerdo.
            filho++;
        }
        if (temp <= heap[filho]) break;  //Se o valor temporário já estiver no lugar certo.
        heap[i] = heap[filho];  //Caso contrário, move o filho para cima
        i = filho;  //continua descendo para o próximo nível.
    }
    heap[i] = temp;  //Coloca o valor temporário na posição correta.

    return menor;  //Retorna o menor valor removido.
}

void selecao(FILE *in, FILE *out){
    int heap[MEM_SIZE];
    int tam_heap = 0;
    int auxReg;
    int marcador = -1;

    for (int i = 0; i < MEM_SIZE; i++){
        if(fread(&auxReg, sizeof(int), 1, in)){
            insereHeap(heap, &tam_heap, auxReg);
        }
    } //preenche a heap com os registros

    while (tam_heap > 0){
        int menor = remover(heap, &tam_heap);
        fwrite(&menor, sizeof(int), 1, out);

        if (fread(&auxReg, sizeof(int), 1, in)) {
            if (auxReg >= menor) {
                insereHeap(heap, &tam_heap, auxReg);
            } else { 
                fwrite(&marcador, sizeof(int), 1, out);
                insereHeap(heap, &tam_heap, auxReg);
            } //Marcador de nova rodada.
        }
    }

    fwrite(&marcador, sizeof(int), 1, out); //Marcar o fim da última rodada.
}