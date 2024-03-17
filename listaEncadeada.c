#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* elements; 
    int numberOfElements;
    int size;
    int reallocCount;

}t_sorted_list;

int* allocateList(t_sorted_list* list, int size){
    list->elements = (int*) malloc(sizeof(int) * size);
    return list->elements;
}

t_sorted_list* allocateStruct(int size){
    t_sorted_list* list = malloc(sizeof(t_sorted_list));
    allocateList(list,size);
    return list;
}


// SIZE MANAGER
int reallocSize(t_sorted_list* list){
    list->elements = realloc(list->elements,sizeof(int) * (list->size + ((list->size/2) * list->reallocCount)));
    list->reallocCount++;
    return 1;
}

// ADD ELEMENTS
int insertElement(t_sorted_list* list, int elem){
    int index = findPosition(list,elem);
    freeIndexPosition(list,index);
    list->elements[index] = elem;
    return 1;
}

int findPosition(t_sorted_list* list,int elem){
    int index = 0;

    return index;
}

int freeIndexPosition(t_sorted_list* list, int index){
    if (list->numberOfElements > list->size){
        return 0;
    }

    if (list->numberOfElements ==  list->size){
        reallocSize(list);
    }

    int aux;
    for (int i = list->numberOfElements; i > index; i--){
        list->elements[i] = list->elements[i-1];
    }
    list->elements[index] = 0;
    return 1;
} 


// REMOVE ELEMENTS
void pop(t_sorted_list* list){

}

void remove_by_index(t_sorted_list* list,int index){

}

void remove_by_element(t_sorted_list* list,int elem){

}

void clear(t_sorted_list* list){

}


// LIST INFOS
void get(t_sorted_list* list,int index){

}

void indexOf(t_sorted_list* list,int elem){

}

void size(t_sorted_list* list){

}

void is_Empty(t_sorted_list* list){

}

void count(t_sorted_list* list,int elem){

}






















int main(){
    int size;
    char escolha;
    int numero;

    printf("Digite o size do vetor: ");
    scanf("%d", &size);

    // int *array = arrayDinamico(size);

    while(escolha == 's'){
        printf("Deseja adicionar um value a lista? (s/n)");
        scanf(" %c", &escolha);
        switch(escolha){
            case 's':
                printf("Digite um value: ");
                scanf("%d", &numero);
                // adicionarValor(array, numero);
                break;

            case 'n':
                printf("Programa encerrado");
                break;

            default:
                printf("ERRO: value invalido inserido");
        }
    }

    printf("%d", numero);
