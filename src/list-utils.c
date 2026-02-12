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

List* create_list() {
    List* new_list = malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void destroy_list(List* list) {
    if (!list) return;

    Node* iterator = list->head;
    Node* next;

    while (iterator != NULL) {
        next = iterator->next;
        free(iterator);         
        iterator = next;        
    }

    free(list);
}

int get_size(List* list) {
    if (!list) return -1;

    return list->size;
}

bool is_empty(List* list) {
    if (!list) return false;

    return list->size == 0;
}