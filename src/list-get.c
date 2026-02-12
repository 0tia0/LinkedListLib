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

Node* get_at(List *list, int index) {
    Node* node = NULL;
    if (!list ||  is_empty(list)) return node;

    if(index >= list->size) {
        return get_last(list);
    }
    
    if (index <= 0) {
        return get_first(list);
    }

    Node* iterator = list->head;

    for(int i=0; i<index; i++) {
        iterator = iterator->next;
    }

    return iterator;
}

Node* get_first(List *list) {
    Node* node = NULL;
    if (!list ||  is_empty(list)) return node;

    node = list->head;
    return node;
}

Node* get_last(List *list) {
    Node* node = NULL;
    if (!list ||  is_empty(list)) return node;

    node = list->tail;
    return node;
}