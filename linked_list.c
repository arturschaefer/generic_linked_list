#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "linked_list.h"

//define abaixo desabilita o assert
//#define DEBUG

int is_empty(TList *ls){
    if(ls->head==NULL)
        return 1;
    return 0;
}

void start(TList *ls){
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
}

void clean_list(TList *ls){
    TNode *atual = ls->tail;
    TNode *aux;
    if(atual!=ls->head){
        aux = atual->prev;
        free(atual);
        ls->tail = aux;
        clean_list(ls);
    }else{
        ls->head=NULL;
        ls->tail=NULL;
        free(atual);
    }
}

void percorre_lista(TList *ls, void (*cb)(void*)){
    TNode *aux;
    aux = ls->head;
    assert(is_empty(ls));
    while(aux!=NULL){
        cb(aux->data);
        aux = aux->next;
    }
}

TNode *iterate_with_interruption(TList *ls, comparator buscar, void *dado_procurado){
    TNode *aux = ls->head;
    int r;

    if (is_empty(ls)) return FALSE;

    while(aux!=NULL){
        r = buscar(aux->data,dado_procurado);
        if(r == TRUE) return aux;
        aux = aux->next;
    }
    return (FALSE);
}

void push(TList *ls, void *inform, comparator maior){
    TNode *atual = ls->head;

    TNode *novo = malloc(sizeof(TNode));
    novo->data = malloc(ls->element_size);
    memcpy(novo->data, inform, ls->element_size);

    novo->prev = NULL;
    novo->next = NULL;

    if(is_empty(ls)){//PRIMEIRO ELEMENTO DA LISTA
        ls->head = novo;
        ls->tail = novo;
    }else{
        while(atual != NULL){
            //if(memcmp(atual->data,novo->data,sizeof(ls->element_size))>0){
            if (maior(inform, atual->data) == TRUE){
                if(atual == ls->head){//INSERE NO INICIO DA LISTA
                    novo->next = atual;
                    ls->head = novo;
                    atual->prev = novo;
                    break;
                }else{//INSERE NO MEIO DA LISTA
                    novo->next = atual;
                    novo->prev->next = novo;
                    atual->prev = novo;
                    break;
                }
            }else {//INSERE NO FIM DA LISTA
                if(atual->next == NULL){
                    atual->next = novo;
                    ls->tail = novo;
                    novo->prev = atual;
                    break;
                }
            }
            novo->prev = atual;
            atual = atual->next;
        }
    }
    ls->size++;
}

void del_node(TList *ls, TNode *del){
    if(is_empty(ls)){
        printf("\n\nImpossível excluir. Não existe nada cadastrado na lista\n\n");
        return;
    }else{
        if(del == ls->head){//EXCLUI NO INICIO
            if(del->next != NULL){//VERIFICA SE ELE É PRIMEIRO DA LISTA
                ls->head = del->next;
                del->next->prev = NULL;
                del->next = NULL;
            }
            else if(del->next == NULL){//VERIFICA SE ELE E PRIMEIRO DA LISTA E SE ELE ESTA SOZINHO NA LISTA
                ls->tail = NULL;
                ls->head = NULL;
            }
            free(del);
        }else if(del->next != NULL){//EXCLUI NO MEIO DA LISTA
            del->prev->next = del->next;
            del->next->prev = del->prev;
            del->prev = NULL;
            del->next = NULL;
            free(del);
        }
        else{//EXCLUI NO FIM DA LISTA
            ls->tail = del->prev;
            del->prev->next = del->next; //PODE MANDAR APONTAR PRA NULL TAMBEM, TANTO FAZ.
            del->prev = NULL;
            del->next = NULL;
            free(del);
        }
    }
    ls->size--;
}

void list_new(TList *list, int elementSize, free_function freeFn){
    assert(elementSize > 0);
    list->size = 0;
    list->element_size = elementSize;
    list->head = list->tail = NULL;
    list->free_fn = freeFn;
}

void list_destroy(TList *list)
{
    TNode *atual;
    while(list->head != NULL) {
        atual = list->head;
        list->head = atual->next;

        if(list->free_fn) {
            list->free_fn(atual->data);
        }

        free(atual->data);
        free(atual);
    }
}

void list_prepend(TList *list, void *element){
    TNode *node = malloc(sizeof(TNode));
    node->data = malloc(list->element_size);
    memcpy(node->data, element, list->element_size);

    node->next = list->head;
    node->prev = NULL;
    list->head = node;

    if(!list->tail) {
        list->tail = list->head;
    }

    list->size++;
}

void list_append(TList *list, void *element){
    TNode *node = malloc(sizeof(TNode));
    node->data = malloc(list->element_size);
    node->next = NULL;

    memcpy(node->data, element, list->element_size);

    if(list->size == 0) {
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

void list_for_each(TList *list, list_iterator iterator){
    assert(iterator != NULL);

    TNode *node = list->head;
    bool result = TRUE;
    while(node != NULL && result){
        result = iterator(node->data);
        node = node->next;
    }
}

void list_head(TList *list, void *element, bool remover){
    assert(list->head != NULL);

    TNode *node = list->head;
    memcpy(element, node->data, list->element_size);

    if(remover) {
        list->head = node->next;
        list->size--;
        free(node->data);
        free(node);
    }
}

void list_tail(TList *list, void *element, bool remove_from_list){
    assert(list->tail != NULL);
    TNode *node = list->tail;
    memcpy(element, node->data, list->element_size);

    if(remove_from_list) {
        list->tail = node->prev;
        list->size--;
        free(node->data);
        free(node);
    }
}

int list_size(TList *list){
    return list->size;
}

void list_for_each_reverse(TList *list, list_iterator iterator){
    assert(iterator != NULL);

    TNode *node = list->tail;
    bool result = TRUE;
    while(node != NULL && result) {
        result = iterator(node->data);
        node = node->prev;
    }
}
