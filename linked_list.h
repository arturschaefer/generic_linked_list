#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * Define um ponteiro para uma função que retorna um void e aceita um único void* argumento,
 * contendo o item para ser limpo
 */
typedef void (*free_function)(void *);

typedef enum { FALSE, TRUE } bool;

/**
 * Define um ponteiro para uma função que retorna bool e aceita um void*
 */
typedef bool (*list_iterator)(void *);

/**
 * Define um ponteiro para uma função que retorna se o primeiro valor é maior que o segundo
 */
typedef bool (*comparator)(void*, void*);

/**
  * @brief Tipo de dados Nó
  * @details Estrutura do nó com dados armazenados em um void*
  **/
typedef struct Node {
    void *data;
    struct Node *prev, *next;
}TNode;


/**
  * @brief Tipo de dados Lista Duplamente Encadeada
  * @details Estrutura de lista encadeada, contendo o tamanho lógico (size) e o tamanho de cada tipo de dados (element_size)
  **/
typedef struct List{
    TNode *head, *tail;
    int size, element_size;
    free_function free_fn;
}TList;

/**
 * @brief list_new
 * @details Cria uma lista nova com o tamanho de bytes de cada elemento
 * @param list
 * @param elementSize
 * @param freeFn
 */
void list_new(TList *list, int elementSize, free_function freeFn);

/**
 * @brief list_destroy
 * @details Destroi a lista utilizando o free_function
 * @param list
 */
void list_destroy(TList *list);

/**
 * @brief list_prepend
 * @details Adiciona um nó no inicio da lista
 * @param list
 * @param element
 */
void list_prepend(TList *list, void *element);

/**
 * @brief list_append
 * @details Adiciona um nó no fim da lista
 * @param list
 * @param element
 */
void list_append(TList *list, void *element);

/**
 * @brief list_size
 * @details Retorna o tamanho da lista.
 * @param list
 * @return
 */
int list_size(TList *list);

/**
 * @brief list_for_each
 * @details
 * @param list
 * @param iterator
 */
void list_for_each(TList *list, list_iterator iterator);

/**
 * @brief list_head
 * @details Copia o primeiro elemento da lista para o *element. É opicional remover o primeiro da lista
 * @param list
 * @param element
 * @param removeFromList
 */
void list_head(TList *list, void *element, bool remove_from_list);

/**
 * @brief list_tail
 * @details Copia o último elemento da lista para o *element. É opicional remover o último elemento da lista
 * @param list
 * @param element
 */
void list_tail(TList *list, void *element, bool remove_from_list);

/**
 * @brief is_empty
 * @details Verifica se a lista está vazia. Retorna 1 se sim, ou 0 se não estiver
 * @param ls
 * @return
 */
int is_empty(TList *ls);

/**
 * @brief list_for_each_reverse
 * @details @param list
 * @param iterator
 */
void list_for_each_reverse(TList *list, list_iterator iterator);

/**
 * @brief start
 * @details Inicia uma lista sem utilizar o element_size.
 * @param ls
 */
void start(TList *ls);

/**
 * @brief clean_list
 * @details Limpa lista da memória, utilizando recursão
 * @param ls
 */
void clean_list(TList *ls);

/**
 * @brief percorre_lista
 * @details Iterator com função callback
 * @param ls
 */
void percorre_lista(TList *ls, void (*cb)(void*));

/**
 * @brief push
 * @details Insere um nó na lista ordenando crescentemente
 * @param ls
 * @param inform
 */
void push(TList *ls, void *inform, comparator maior);

/**
 * @brief percorre_lista_interrupcao
 * @details Percorre a lista em busca de um dado. Se encontrar retorna o nó encontrad, senão retorna 0
 * @param ls
 * @param dado_procurado
 * @return
 */
TNode *iterate_with_interruption(TList *ls, comparator buscar, void *dado_procurado);
//TNode *iterate_with_interruption(TList *ls, int (*cb)(void*,void*), void *dado_procurado);


/**
 * @brief del_node
 * @details Deleta um nó da lista
 * @param ls
 * @param del
 */
void del_node(TList *ls, TNode *del);

#endif // LINKED_LIST_H
