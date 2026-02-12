#include <stdio.h>
#include "list.h"

typedef struct {
    char name[50];
    double price;
} Item;

void print_item(void* data) {
    Item item = *(Item*)data;
    printf("- %s: Euro %.2f\n", item.name, item.price);
}

int main() {
    List* shopping_list = create_list();

    push_back(shopping_list, &(Item){"Milk", 1.50});
    push_back(shopping_list, &(Item){"Bread", 2.20});
    push_back(shopping_list, &(Item){"Eggs", 3.10});
    push_back(shopping_list, &(Item){"Coffee", 5.80});

    pop_at(shopping_list, 2);

    printf("Shopping List:\n\n");

    list_foreach(shopping_list, print_item);

    return 0;
}
