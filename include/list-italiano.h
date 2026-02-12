/*
*
*  Created on:          Oct 2025
*
*  Code written by:     Mattia Marelli (https://github.com/0tia0) (mattia.marelli.work@gmail.com)
*  Version:             1.10
*
*  License:             Linked List C Lib © 2025 by Mattia Marelli is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International
*                       CC BY-NC-SA 4.0 https://creativecommons.org/licenses/by-nc-sa/4.0/
*
*/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

// Nodo della lista che contiene un dato generico (void*) e un puntatore al nodo successivo
typedef struct s_node {
    void* data;
    struct s_node* next;
} Node;

// Struttura della lista che contiene il puntatore alla testa, alla coda e la dimensione della lista
typedef struct {
    Node* head;
    Node* tail;
    int size;
} List;

//
// GENERIC FUNCTIONS (list-utils.c)
//

/**
 * @brief Inizializza la lista 
 * 
 * @return List* indirizzo lista appena inizializzata
 */
List* create_list();

/**
 * @brief Distrugge la lista e libera la memoria occupata da essa
 * 
 * @param list lista da distruggere
 */
void destroy_list(List* list);

/**
 * @brief Restituisce la dimensione della lista
 * 
 * @param list lista di cui ottenere la dimensione
 * @return int dimensione della lista
 */
int get_size(List* list);

/**
 * @brief Restituisce true se la lista è vuota, false altrimenti
 * 
 * @param list lista da controllare
 * @return true se la lista è vuota
 * @return false se la lista non è vuota
 */
bool is_empty(List* list);

//
// PUSH FUNCTIONS (list-push.c)
//

/**
 * @brief Aggiunge un elemento alla fine della lista
 * 
 * @param list lista a cui aggiungere l'elemento
 * @param data elemento da aggiungere
 */
void push_back(List* list, void* data);

/**
 * @brief Aggiunge un elemento all'inizio della lista
 * 
 * @param list lista a cui aggiungere l'elemento
 * @param data elemento da aggiungere
 */
void push_front(List* list, void* data);

/**
 * @brief Aggiunge un elemento in una posizione specifica della lista. 
 *        L'elemento viene aggiunto in posizione "index", partendo da 0 e ciò che ci si trovava in quella posizione viene spostato in avanti di una posizione insieme al resto della lista.
 *        Se l'indice è maggiore o uguale alla dimensione della lista, l'elemento viene aggiunto alla fine. Se l'indice è minore o uguale a 0, l'elemento viene aggiunto all'inizio.
 * 
 * @param list lista a cui aggiungere l'elemento
 * @param data elemento da aggiungere
 * @param index posizione in cui aggiungere l'elemento (partendo da 0)
 */
void push_at(List* list, void* data, int index);

//
// POP FUNCTIONS (list-pop.c)
//

/**
 * @brief Rimuove un elemento dalla fine della lista
 * 
 * @param list lista a cui rimuove l'elemento
 * @return Node elemento rimosso dalla lista se dovesse servire all'utenete
 */
Node pop_back(List* list);

/**
 * @brief Rimuove un elemento all'inizio della lista
 * 
 * @param list lista a cui rimuove l'elemento
 * @return Node elemento rimosso dalla lista se dovesse servire all'utenete
 */
Node pop_front(List* list);

/**
 * @brief Rimuove un elemento in una posizione specifica della lista.
 *        L'elemento viene rimosso in posizione "index", partendo da 0 e ciò che ci si trovava in quella posizione viene spostato indietro di una posizione insieme al resto della lista.
 *        Se l'indice è maggiore o uguale alla dimensione della lista, l'elemento viene rimosso dalla fine. Se l'indice è minore o uguale a 0, l'elemento viene rimosso dall'inizio.
 * 
 * @param list lista a cui rimuove l'elemento
 * @param index posizione in cui rimuovere l'elemento (partendo da 0)
 * @return Node elemento rimosso dalla lista se dovesse servire all'utenete
 */
Node pop_at(List* list, int index);

//
// GET FUNCTIONS (list-get.c)
//

/**
 * @brief Restituisce il nodo in una posizione specifica della lista.
 *        Se l'indice è maggiore o uguale alla dimensione della lista, viene restituito l'ultimo nodo. Se l'indice è minore o uguale a 0, viene restituito il primo nodo.
 * 
 * @param list lista da cui ottenere il nodo
 * @param index posizione del nodo da ottenere (partendo da 0)
 * @return Node* nodo nella posizione specificata o NULL se non esiste
 */
Node* get_at(List *list, int index);

/**
 * @brief Resituisce il primo nodo della lista.
 * 
 * @param list lista da cui ottenere il primo nodo
 * @return Node* nodo in testa alla lista o NULL se la lista è vuota
 */
Node* get_first(List *list);

/**
 * @brief Resituisce l'ultimo nodo della lista.
 * 
 * @param list lista da cui ottenere l'ultimo nodo
 * @return Node* nodo in coda alla lista o NULL se la lista è vuota
 */
Node* get_last(List *list);

//
// FOR EACH FUNCTIONS (list-foreach.c)
//

/**
 * @brief Esegue una funzione passata a parametro su ogni elemento della lista, partendo dal primo fino all'ultimo.
 * 
 * @param list lista su cui eseguire la funzione
 * @param func funzione da eseguire su ogni elemento della lista
 */
void list_foreach(List* list, void (*func)(void*));

/** 
 * TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO TODO 
 * 
 * @brief Esegue una funzione passata a parametro su ogni elemento della lista, partendo dall'ultimo fino al primo.
 * 
 * @param list lista su cui eseguire la funzione
 * @param func funzione da eseguire su ogni elemento della lista
 */
void list_foreach_reversed(List* list, void (*func)(void*));

#endif // LIST_H