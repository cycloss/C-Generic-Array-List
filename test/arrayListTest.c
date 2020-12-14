#include "../src/arrayList.h"
#include <stdio.h>
#include <stdlib.h>

#define COUNT 6

void printItem(void* item) {
    printf("Value: %i\n", *(int*)item);
}

void printList(arrayList* l) {
    iterateListItems(l, printItem);
}

int main() {
    arrayList* l = createArrayList(5, 0);
    for (int i = 0; i < COUNT; i++) {
        int* n = malloc(sizeof(int));
        *n = i + 1;
        appendToAl(l, n);
    }

    printList(l);
    int removeInd = COUNT / 2;
    int* item = removeItemAt(l, removeInd);
    printf("Removed item from index %i: %i\n", removeInd, *item);
    free(item);
    printList(l);
    puts("Reversing list...");
    reverseAl(l);
    printList(l);
    freeAl(l, true);
}