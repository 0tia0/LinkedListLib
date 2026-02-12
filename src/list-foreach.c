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

void list_foreach(List* list, void (*function)(void*)) {
    if (!list || is_empty(list) || !function) {return;}

    Node* iterator = list->head;
    while (iterator != NULL) {
        function(iterator->data);
        iterator = iterator->next;
    }
}

void list_foreach_reversed(List* list, void (*function)(void*)) {
    // DA FARE ANCORA 
}
