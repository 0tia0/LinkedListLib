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

// List node containing a generic payload (void*) and a pointer to the next node.
typedef struct s_node {
    void* data;
    struct s_node* next;
} Node;

// List structure holding head and tail pointers plus the list size.
typedef struct {
    Node* head;
    Node* tail;
    int size;
} List;

//
// UTILITY FUNCTIONS (list-utils.c)
//

/**
 * @brief Initialize an empty list.
 *
 * @return Pointer to the newly allocated list, or NULL on allocation failure.
 */
List* create_list();

/**
 * @brief Destroy a list and free its nodes.
 *
 * @param list List to destroy. Safe to pass NULL.
 *
 * @note The node payloads are not freed.
 */
void destroy_list(List* list);

/**
 * @brief Return the list size.
 *
 * @param list List to query.
 * @return Number of elements, or -1 if list is NULL.
 */
int get_size(List* list);

/**
 * @brief Check whether the list is empty.
 *
 * @param list List to check.
 * @return true if the list is empty, false otherwise.
 */
bool is_empty(List* list);

//
// PUSH FUNCTIONS (list-push.c)
//

/**
 * @brief Append an element to the end of the list.
 *
 * @param list Target list.
 * @param data Element payload to store.
 *
 * @note No-op if list or data is NULL.
 */
void push_back(List* list, void* data);

/**
 * @brief Prepend an element to the beginning of the list.
 *
 * @param list Target list.
 * @param data Element payload to store.
 *
 * @note No-op if list or data is NULL.
 */
void push_front(List* list, void* data);

/**
 * @brief Insert an element at a specific position.
 *        The element is inserted at index (0-based) and the following elements are shifted forward.
 *        If index >= size, the element is appended. If index <= 0, the element is prepended.
 *
 * @param list Target list.
 * @param data Element payload to store.
 * @param index Insert position (0-based).
 *
 * @note No-op if list or data is NULL.
 */
void push_at(List* list, void* data, int index);

//
// POP FUNCTIONS (list-pop.c)
//

/**
 * @brief Remove the last element from the list.
 *
 * @param list Target list.
 * @return Copy of the removed node, or a zeroed Node if the list is NULL or empty.
 */
Node pop_back(List* list);

/**
 * @brief Remove the first element from the list.
 *
 * @param list Target list.
 * @return Copy of the removed node, or a zeroed Node if the list is NULL or empty.
 */
Node pop_front(List* list);

/**
 * @brief Remove the element at a specific position.
 *        The element is removed at index (0-based) and the following elements are shifted backward.
 *        If index >= size, the last element is removed. If index <= 0, the first element is removed.
 *
 * @param list Target list.
 * @param index Removal position (0-based).
 * @return Copy of the removed node, or a zeroed Node if the list is NULL or empty.
 */
Node pop_at(List* list, int index);

//
// GET FUNCTIONS (list-get.c)
//

/**
 * @brief Return the node at a specific index.
 *        If index >= size, the last node is returned. If index <= 0, the first node is returned.
 *
 * @param list Source list.
 * @param index Node position (0-based).
 * @return Node* Pointer to the node at the requested position, or NULL if not found.
 */
Node* get_at(List *list, int index);

/**
 * @brief Return the first node of the list.
 *
 * @param list Source list.
 * @return Node* Pointer to the head node, or NULL if the list is empty.
 */
Node* get_first(List *list);

/**
 * @brief Return the last node of the list.
 *
 * @param list Source list.
 * @return Node* Pointer to the tail node, or NULL if the list is empty.
 */
Node* get_last(List *list);

//
// FOR EACH FUNCTIONS (list-foreach.c)
//

/**
 * @brief Apply a callback to each element from first to last.
 *
 * @param list Target list.
 * @param func Callback invoked with each node's data.
 */
void list_foreach(List* list, void (*func)(void*));

/**
 * @brief Apply a callback to each element from last to first.
 *
 * @param list Target list.
 * @param func Callback invoked with each node's data.
 *
 * @note TODO: not implemented yet.
 */
void list_foreach_reversed(List* list, void (*func)(void*));

#endif // LIST_H