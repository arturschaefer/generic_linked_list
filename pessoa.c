#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "pessoa.h"
void list_with_ints(TList *ls){
    list_for_each (ls, iterate_int);
}

void list_with_strings(TList *ls){
    list_for_each (ls, iterate_string);
    list_destroy (ls);
}

bool iterate_int(void *data){
    printf("%d\n", *(int *)data);
    return TRUE;
}

bool iterate_string(void *data){
    printf("%s\n", *(char **)data);
    return TRUE;
}

void free_string(void *data){
    free(*(char **)data);
}

bool comparar_pessoa(void *a, void *b){
    TPessoa *p_a = (TPessoa*)a, *p_b = (TPessoa*)b;
    if (strcmp(p_a->name, p_b->name) == 0)
        return (*(int*)a < *(int*)b) ? TRUE : FALSE;
    else if (strcmp(p_a->name, p_b->name) < 0)
        return TRUE;
    return FALSE;
}

bool buscar_dado(void* a, void* b){
    if (*(int*)a == *(int*)b) return TRUE;
    return FALSE;
}

void imprime_pessoa(TList *ls){
    TPessoa *pes;
    TNode *aux = ls->head;
    while (aux != NULL){
        pes = (TPessoa*)aux->data;
        printf("%s %d\n", pes->name, pes->age);
        aux = aux->next;
    }
}
