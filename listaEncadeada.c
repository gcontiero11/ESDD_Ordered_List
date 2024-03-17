#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* elements; 
    int indexLastElement;
    int size;
    int reallocCount;

}orderedList;

int arrayDinamico(int tamanho){
    int *array = (int*) malloc(sizeof(int) * tamanho);
    return array;
}

void adicionarValor(int array, int valor){

}






















int main(){
    int tamanho;
    char escolha;
    int numero;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // int *array = arrayDinamico(tamanho);

    while(escolha == 's'){
        printf("Deseja adicionar um valor a lista? (s/n)");
        scanf(" %c", &escolha);
        switch(escolha){
            case 's':
                printf("Digite um valor: ");
                scanf("%d", &numero);
                // adicionarValor(array, numero);
                break;

            case 'n':
                printf("Programa encerrado");
                break;

            default:
                printf("ERRO: valor invalido inserido");
        }
    }

    printf("%d", numero);
