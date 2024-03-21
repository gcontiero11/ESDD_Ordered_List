#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct{
    int* elements; 
    int numberOfElements;
    int size;
    int reallocCount;

} t_sorted_list;
int setSize(t_sorted_list* list, int newSize);
int allocateList(t_sorted_list* list,int size);
t_sorted_list* allocateStruct(int size);
int reallocSize(t_sorted_list* list);
int freeIndexPosition(t_sorted_list* list, int index);
int findPositionToInsert(t_sorted_list* list, int elem);
int insertElement(t_sorted_list* list, int elem);
int removeByIndex(t_sorted_list* list, int index);
int count(t_sorted_list *list, int elem);
int clear(t_sorted_list* list);
int getNumber(t_sorted_list* list, int index, int *number);
int indexOf(t_sorted_list* list, int elem);
int size(t_sorted_list* list);
int isEmpty(t_sorted_list* list);
int removeElement(t_sorted_list* list, int elem);
int pop(t_sorted_list *list);
int listDestroyer(t_sorted_list *list);
void printList(t_sorted_list *list);

#endif