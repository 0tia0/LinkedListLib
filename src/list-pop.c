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

#include "list.h"

Node pop_back(List* list) {
    Node removed_item = {0};
    if (!list || is_empty(list)) return removed_item;

    if(get_size(list) == 1) {
        removed_item = *list->tail;

        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return removed_item;
    }

    removed_item = *list->tail;

    Node* before_iterator = NULL;
    Node* iterator = list->head;
    while (iterator->next != NULL) {
        before_iterator = iterator;
        iterator = iterator->next;
    }

    before_iterator->next = NULL;
    list->tail = before_iterator;

    free(iterator);
    list->size--;
    
    return removed_item; 
}

Node pop_front(List* list) {
    Node removed_item = {0};
    if (!list || is_empty(list)) return removed_item;

    if (get_size(list) == 1) {
        removed_item = *list->head;

        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return removed_item;
    }

    removed_item = *list->head;

    Node* old_head = list->head;
    list->head = list->head->next;

    free(old_head);
    list->size--;
  
    return removed_item; 
}

Node pop_at(List* list, int index) {
    Node removed_item = {0};
    if (!list || is_empty(list)) return removed_item;

    if (get_size(list) == 1) {
        // Se è presente un solo elemento mi baso sui controllo e il sistema gia realizzato il precedenza con stesso scopo
        return pop_front(list);
    } 

    if(index >= list->size) {
        return pop_back(list);
    }
    
    if (index <= 0) {
        return pop_front(list);
    }
    
    Node* before_iterator = NULL;
    Node* iterator = list->head;
    for (int i=0; i<index; i++) {
        before_iterator = iterator;
        iterator = iterator->next;
    }

    removed_item = *iterator;
    before_iterator->next = iterator->next;
    
    free(iterator);
    list->size--;

    return removed_item;
}