#include <stdio.h>
#include <stdlib.h>
// #include "listaEncadeada.h"

typedef struct{
    int* elements; 
    int numberOfElements;
    int size;
    int reallocCount;
} t_sorted_list;

// CREATE FUNCTIONS
int setSize(t_sorted_list* list, int newSize){ // check
    list->size = newSize;
    return 1;
}

int allocateList(t_sorted_list* list,int size){  // check
    list->elements = (int*) malloc(sizeof(int) * size);
    return 1;
}

t_sorted_list* allocateStruct(int size){  // check
    t_sorted_list* list = malloc(sizeof(t_sorted_list));
    allocateList(list,size);
    list->numberOfElements = 0;
    list->reallocCount = 1;
    list->size = size;
    return list;
}

// SIZE MANAGER
int reallocSize(t_sorted_list* list){  // check
    int newSize = list->size + ((list->size/2) * list->reallocCount);
    list->elements = realloc(list->elements,sizeof(int) * (newSize));
    list->reallocCount++;
    setSize(list,newSize);
    return 1;
}

// ADD ELEMENTS
int freeIndexPosition(t_sorted_list* list, int index){  // check
    if (list->numberOfElements ==  list->size){
        reallocSize(list);
    }
    if (index == list->numberOfElements){
        return 1;
    }

    for (int i = list->numberOfElements; i > index; i--){
        list->elements[i] = list->elements[i-1];
    }
    list->elements[index] = 0;
    return 1;
}

int findPositionToInsert(t_sorted_list* list, int elem){  // check
    if (elem < list->elements[0]){
        return 0;
    }
    if (elem>list->elements[list->numberOfElements-1]){
        return list->numberOfElements;
    }
    for (int i = 1; i < list->numberOfElements; i++){
        if (elem>=list->elements[i-1] && elem<=list->elements[i]){
            return i;
        }
    } 
    return -1;
}

int insertElement(t_sorted_list* list, int elem){  // check
    int index = findPositionToInsert(list,elem);
    freeIndexPosition(list,index);
    list->elements[index] = elem;
    list->numberOfElements++;
    return 1;
}

// REMOVE ELEMENTS
int pop(t_sorted_list *list) {  // check
  list->numberOfElements--;
  return 1;
}

int removeByIndex(t_sorted_list* list, int index){  // check
    if (index < 0 || index > list->numberOfElements-1){
        return 0;
    }
    for (int i = index; i < list->numberOfElements - 1; i++){
        list->elements[i] = list->elements[i+1];
    }
    list->numberOfElements--;
    return 1;
}

int removeElement(t_sorted_list* list, int elem){  // check
    for(int i = 0; i < list->numberOfElements; i++){
        if(list->elements[i] == elem) {
           for (int j = i; j < list->numberOfElements - 1; j++) {
                list->elements[j] = list->elements[j + 1];
            }
            list->numberOfElements--;
            return 1;
        }
    }
    return 0;
}

int clear(t_sorted_list* list){
    free(list->elements);
    return 1;
}

// LIST INFOS
int getNumber(t_sorted_list* list, int index){
    if(index > list->numberOfElements) return 0;
    for(int count = 0; count < list->numberOfElements; count++){
        if(count == index) return list->elements[count];
    }

    return 404;
}

int indexOf(t_sorted_list* list,int elem){
  int i = 0;
    for(int index = 0; i < list->numberOfElements; index++){
        if(list->elements[i] == elem) return index;
    }
    return -1;
}

int size(t_sorted_list* list){
    return list->numberOfElements;
}

int isEmpty(t_sorted_list* list){
    if(list->numberOfElements == 0) return 1;
    return 0;
}

int count(t_sorted_list *list, int elem){
    int contador = 0;
    for (int i = 0; i < list->numberOfElements; i++){
        if (elem == list->elements[i]){
            contador += 1;
        }
    }
    return contador;
}

void printList(t_sorted_list *list){
    for(int i = 0; i < list->numberOfElements; i++){
        printf("%d ", list->elements[i]);
    }
    printf("\n");
}

int main(){
    t_sorted_list *list;
    list = allocateStruct(5);

    insertElement(list, 10);
    
    insertElement(list, 5);
    insertElement(list, 7);
    printf("PASSOU\n");
    insertElement(list, 9);
    insertElement(list, 3);
    insertElement(list, 1);
    insertElement(list, 20);
    insertElement(list, -1);

    printList(list);

    pop(list);
    printList(list);

    removeByIndex(list, 2);
    printList(list);

    removeElement(list, 7);
    printList(list);

    printf("%d\n", getNumber(list, 28));
}