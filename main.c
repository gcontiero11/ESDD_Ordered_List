#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(){
    t_sorted_list* sortedList = allocateStruct(30);
    printf("%d\n",sortedList->numberOfElements);
    printf("%d\n",sortedList->reallocCount);
    printf("%d\n",sortedList->size);
    reallocSize(sortedList);
    printf("%d\n",sortedList->size);
}