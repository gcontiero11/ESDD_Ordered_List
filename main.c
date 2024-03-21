#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  t_sorted_list *list;
  list = allocateStruct(5);

  insertElement(list, 10);
  insertElement(list, 5);
  insertElement(list, 7);
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
  int *number = malloc(sizeof(int));
  printf("%d\n", getNumber(list, 3, number));
  printf("%d\n", *number);
  printf("%d\n", indexOf(list, 28));
  printf("%d\n", size(list));
  insertElement(list, 1);
  printList(list);
  printf("%d\n", count(list, 1));
  printf("%d\n", count(list, 11));
  printf("%d\n", isEmpty(list));
  printf("%d\n", clear(list));
  printf("%d\n", listDestroyer(list));
}