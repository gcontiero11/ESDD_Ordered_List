#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

// CREATE FUNCTIONS
int setSize(t_sorted_list *list, int newSize) {
  list->size = newSize;
  return 1;
}

int allocateList(t_sorted_list *list, int size) {
  list->elements = (int *)malloc(sizeof(int) * size);
  return 1;
}

t_sorted_list *allocateStruct(int size) {
  t_sorted_list *list = malloc(sizeof(t_sorted_list));
  allocateList(list, size);
  list->numberOfElements = 0;
  list->reallocCount = 1;
  list->size = size;
  return list;
}

// SIZE MANAGER
int reallocSize(t_sorted_list *list) {
  int newSize = list->size + ((list->size / 2) * list->reallocCount);
  list->elements = realloc(list->elements, sizeof(int) * (newSize));
  list->reallocCount++;
  setSize(list, newSize);
  return 1;
}

// ADD ELEMENTS
int freeIndexPosition(t_sorted_list *list, int index) {
  if (list->numberOfElements == list->size) {
    reallocSize(list);
  }
  if (index == list->numberOfElements) {
    return 1;
  }
  for (int i = list->numberOfElements; i > index; i--) {
    list->elements[i] = list->elements[i - 1];
  }
  list->elements[index] = 0;
  return 1;
}

int findPositionToInsert(t_sorted_list *list, int elem) {
  if (elem < list->elements[0]) {
    return 0;
  }
  if (elem > list->elements[list->numberOfElements - 1]) {
    return list->numberOfElements;
  }
  for (int i = 1; i < list->numberOfElements; i++) {
    if (elem >= list->elements[i - 1] && elem <= list->elements[i]) {
      return i;
    }
  }
  return -1;
}

int insertElement(t_sorted_list *list, int elem) {
  int index = findPositionToInsert(list, elem);
  freeIndexPosition(list, index);
  list->elements[index] = elem;
  list->numberOfElements++;
  return 1;
}

// REMOVE ELEMENTS
int pop(t_sorted_list *list) {
  list->numberOfElements--;
  return 1;
}

int removeByIndex(t_sorted_list *list, int index) {
  if (index < 0 || index > list->numberOfElements - 1) {
    return 0;
  }
  for (int i = index; i < list->numberOfElements - 1; i++) {
    list->elements[i] = list->elements[i + 1];
  }
  list->numberOfElements--;
  return 1;
}

int removeElement(t_sorted_list *list, int elem) {
  for (int i = 0; i < list->numberOfElements; i++) {
    if (list->elements[i] == elem) {
      for (int j = i; j < list->numberOfElements - 1; j++) {
        list->elements[j] = list->elements[j + 1];
      }
      list->numberOfElements--;
      return 1;
    }
  }
  return 0;
}

int clear(t_sorted_list *list) {
  list->numberOfElements = 0;
  return 1;
}

// LIST INFOS
int getNumber(t_sorted_list *list, int index, int *number) {
  if (index > list->numberOfElements) {
    return 0;
  }
  for (int count = 0; count < list->numberOfElements; count++) {
    if (count == index) {
      *number = list->elements[count];
      return 1;
    }
  }

  return -404;
}

int indexOf(t_sorted_list *list, int elem) {
  for (int index = 0; index < list->numberOfElements; index++) {
    if (list->elements[index] == elem)
      return index;
  }
  return -1;
}

int size(t_sorted_list *list) { // check
  return list->numberOfElements;
}

int isEmpty(t_sorted_list *list) { // check
  if (list->numberOfElements == 0)
    return 1;
  return 0;
}

int count(t_sorted_list *list, int elem) { // check
  int contador = 0;
  for (int i = 0; i < list->numberOfElements; i++) {
    if (elem == list->elements[i]) {
      contador += 1;
    }
  }
  return contador;
}

int listDestroyer(t_sorted_list *list) {
  free(list->elements);
  free(list);
  return 1;
}

void printList(t_sorted_list *list) {
  for (int i = 0; i < list->numberOfElements; i++) {
    printf("%d ", list->elements[i]);
  }
  printf("\n");
}