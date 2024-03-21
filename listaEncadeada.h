#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct{
    int* elements; 
    int numberOfElements;
    int size;
    int reallocCount;

} t_sorted_list;

int clear(t_sorted_list* list);
int getNumber(t_sorted_list* list, int index);
int indexOf(t_sorted_list* list, int elem);
int size(t_sorted_list* list);
int isEmpty(t_sorted_list* list);
int removeElement(t_sorted_list* list, int elem);
int pop(t_sorted_list *list, int numberOfElements);

#endif