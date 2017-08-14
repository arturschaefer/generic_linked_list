# Generic Linked List

A Generic Doubly Linked List in C. Using struct of a Person as example.

## Status

[![Build Status](https://travis-ci.org/arturschaefer/generic_linked_list.svg?branch=master)](https://travis-ci.org/arturschaefer/generic_linked_list)

## Introdução

Esse projeto foi criado utilizando o QT Creator.
A biblioteca que contém o essencial para lista genérica é [linked_list.h](https://github.com/arturschaefer/generic_linked_list/blob/master/linked_list.h), contendo os cabeçalhos das funções e a definição das structs.

O código das funções está no [linked_list.c](https://github.com/arturschaefer/generic_linked_list/blob/master/linked_list.c).

É possível utilizar esse código para tratar Listas, Pilha e Fila.

Cada função possui a descrição de uso no cabeçalho dentro do [linked_list.h](https://github.com/arturschaefer/generic_linked_list/blob/master/linked_list.h).

Observação: é necessário compilar o main.c e o linked_list.c em conjunto, caso não abra o projeto no QT Creator.

### Pré-Requisitos

Qualquer compilador em C.
Recomendo o [GCC](https://gcc.gnu.org/), é nativo em algumas distros Linux e de fácil instalação no Windows.

## Testes

Testes foram feitos adicionando pessoas no inicio, fim e meio da lista. 
O mesmo procedimento de testes ocorreu para deletar nós.

## IDE

* [QT Creator](https://www.qt.io/ide/) - IDE Utilizada

## Autor

* **Artur Schaefer** - [arturschaefer](https://github.com/arturschaefer)
* **Pseudomuto** - *Inspiração e exemplificação de código* - [Pseudomuto](http://pseudomuto.com/development/2013/05/02/implementing-a-generic-linked-list-in-c/)

## Conhecimentos

* Definição de structs
* Ponteiros
