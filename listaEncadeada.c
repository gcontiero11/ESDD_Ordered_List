#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* elements; 
    int numberOfElements;
    int size;
    int reallocCount;

}t_sorted_list;

// CREATE FUNCTIONS
int setSize(t_sorted_list* list, int newSize){
    list->size = newSize;
}

int allocateList(t_sorted_list* list,int size){
    list->elements = (int*) malloc(sizeof(int) * size);
    return 1;
}

t_sorted_list* allocateStruct(int size){
    t_sorted_list* list = malloc(sizeof(t_sorted_list));
    allocateList(list,size);
    list->numberOfElements = 0;
    list->reallocCount = 1;
    list->size = size;
    return list;
}


// SIZE MANAGER
int reallocSize(t_sorted_list* list){
    int newSize = list->size + ((list->size/2) * list->reallocCount);
    list->elements = realloc(list->elements,sizeof(int) * (newSize));
    list->reallocCount++;
    setSize(list,newSize);
    return 1;
}

// ADD ELEMENTS
int freeIndexPosition(t_sorted_list* list, int index){
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
int findPositionToInsert(t_sorted_list* list,int elem){

}

int insertElement(t_sorted_list* list, int elem){
    int index = findPositionToInsert(list,elem);
    freeIndexPosition(list,index);
    list->elements[index] = elem;
    return 1;
}

// // REMOVE ELEMENTS
void pop(){

}

void remove_by_index(t_sorted_list* list,int index){
    
}

void remove_by_element(t_sorted_list* list,int elem){

}

void clear(t_sorted_list* list){
    clear(list);
    return 1;
}

// LIST INFOS
void get(t_sorted_list* list,int index){
    if(index > list->numberOfElements) return 0;
    for(int count = 0; count < list->numberOfElements; count++){
        
    }
}

void indexOf(t_sorted_list* list,int elem){
    int index = 0;
    for(int i = 0; i < list->numberOfElements; i++){
        if(list->elements[i] == elem) return index;
        index++;
    }
    return index;
}

void size(t_sorted_list* list){

}

void is_Empty(t_sorted_list* list){

}

void count(t_sorted_list* list,int elem){
    return list->numberOfElements;
}






















int main(){
    t_sorted_list* sortedList = allocateStruct(30);
    printf("%d\n",sortedList->numberOfElements);
    printf("%d\n",sortedList->reallocCount);
    printf("%d\n",sortedList->size);
    reallocSize(sortedList);
    printf("%d\n",sortedList->size);
}
