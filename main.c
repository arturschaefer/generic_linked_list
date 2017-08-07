#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "linked_list.h"
#include "pessoa.h"

int main(void){
    int i, r, aux_int;
    void *aux_void;
    clock_t t0, tf;
    double tempo_gasto;
    TList list;
    TPessoa *p1 = (TPessoa*) malloc(5 * sizeof(TPessoa));

    t0 = clock();
    list_new(&list, sizeof(TPessoa), NULL);

    TPessoa p2[] = {{10, "Ab"},
                    {5, "Bc"},
                    {3, "Ds"},
                    {4, "Es"},
                    {2, "Ab"}};

    srand(time(NULL));

    for (i = 0; i < 5; i++){
        r = rand();
        p1[i].age = p2[i].age;
        strcpy(p1[i].name, p2[i].name);
//        list_append(&list, &r);
        aux_void = (void*)&p1[i];
        push(&list,aux_void,comparar_pessoa);
    }
    aux_int = r;

    TNode *aux = list.head;
    i = 0;
    while (aux!= NULL){
        p2[i] = *(TPessoa*)aux->data;
        printf("%d\n", p2[i++].age);
        aux = aux->next;
    }

    printf("\n\n");
    TNode *no_aux = iterate_with_interruption(&list,buscar_dado,&r);
    if (no_aux != NULL){
        printf("Valor encontrado %d\n\n", aux_int);
        del_node(&list, no_aux);
        printf("Valor deletado\n\n");
    }

    //list_with_ints(&list);
    imprime_pessoa(&list);
    list_destroy(&list);
    tf = clock();
    tempo_gasto = ( (double) (tf - t0) ) / (((double)CLOCKS_PER_SEC)/1000);
    printf("Tempo gasto %.2lf\n",tempo_gasto);
}
