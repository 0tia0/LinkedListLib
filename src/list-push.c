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

void push_back(List* list, void* data) {
    if (!list) return;
    if (!data) return;

    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    } 

    list->tail->next = new_node;
    list->tail = new_node;

    list->size++;
}

void push_front(List* list, void* data) {
    if (!list) return;
    if (!data) return;

    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(list)) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    } 

    new_node->next = list->head;
    list->head = new_node;

    list->size++;
}

void push_at(List* list, void* data, int index) {
    if (!list) return;
    if (!data) return;

    if(index >= list->size || is_empty(list)) {
        push_back(list, data);
        return;
    }
    
    if (index <= 0) {
        push_front(list, data);
        return;
    }

    Node* new_node = malloc(sizeof(Node));
    Node* iterator = list->head;

    if (!new_node) return;

    new_node->data = data;
    new_node->next = NULL;

    for(int i=0; i<index-1; i++) {
        iterator = iterator->next;
    }

    new_node->next = iterator->next;
    iterator->next = new_node;
    
    list->size++;
}