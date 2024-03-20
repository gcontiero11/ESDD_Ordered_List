#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"


typedef struct{
    int* elements; 
    int numberOfElements;
    int size;
    int reallocCount;

}t_sorted_list;

int allocateList(int size){
    int *array = (int*) malloc(sizeof(int) * size);
    return array;
}

// SIZE MANAGER
int reallocSize(t_sorted_list list){
    list.elements = realloc(list.elements,sizeof(int) * (list.size + ((list.size/2) * list.reallocCount)));
}

// ADD ELEMENTS
int insertElement(t_sorted_list list, int elem){
    int index = findPosition(list,elem);
    freeIndexPosition(list,index);
    return 1;
}

int findPosition(t_sorted_list list,int elem){
    int index = 0;

    return index;
}

int freeIndexPosition(t_sorted_list list, int index){
    if (list.numberOfElements ==  list.size){
        reallocSize(list);
    }
    int aux;
    for (int i = list.numberOfElements - 1; i > index; i++){

           
        
    }
    
} 


// REMOVE ELEMENTS
void pop(){

}

void remove_by_index(t_sorted_list list,int index){
    
}

void remove_by_element(t_sorted_list list,int elem){

}

void clear(t_sorted_list list){

}


// LIST INFOS
void get(t_sorted_list list,int index){

}

void indexOf(t_sorted_list list,int elem){

}

void size(t_sorted_list list){

}

void is_Empty(t_sorted_list list){

}

void count(t_sorted_list list,int elem){

}