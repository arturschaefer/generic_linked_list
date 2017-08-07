#ifndef PESSOA_H
#define PESSOA_H

#include "linked_list.h"

typedef struct pessoa{
    int age;
    char name[100];
}TPessoa;

void list_with_ints(TList *ls);
void list_with_strings(TList *ls);

bool iterate_int(void *data);
bool iterate_string(void *data);
void free_string(void *data);

bool comparar_pessoa(void *a, void *b);
bool buscar_dado(void* a, void* b);
void imprime_pessoa(TList *ls);

#endif // PESSOA_H
