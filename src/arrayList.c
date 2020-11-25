#include "arrayList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void fatalError(char* msg) {
    printf("Fatal error: %s\n", msg);
    exit(1);
}

static void testIndex(arrayList* l, int i) {
    if (i >= l->_nextIndex || i < 0) {
        fatalError("Index out of bounds");
    }
}

arrayList* createArrayList(int startSize, float growthFactor) {
    int size = startSize > 4 ? startSize : 10;
    float gf = growthFactor >= 1.2 ? growthFactor : 1.75;
    arrayList* al = malloc(sizeof(arrayList));
    void** ar = malloc(sizeof(void*) * size);
    if (!(al && ar)) {
        return NULL;
    }
    *al = (arrayList) { size, gf, 0, ar };
    return al;
}

static void expandList(arrayList* l) {
    int newSize = l->_currentSize * l->growthFactor;
    void** newArray = realloc(l->array, sizeof(void*) * newSize);
    if (!newArray) {
        fatalError("arrayList expansion failed");
    }
    printf("Expanding list size from %i to %i\n", l->_currentSize, newSize);
    l->_currentSize = newSize;
    l->array = newArray;
}

void append(arrayList* l, void* item) {
    if (!l) {
        fatalError("arrayList was null");
    }
    if (l->_nextIndex >= l->_currentSize) {
        expandList(l);
        append(l, item);
    } else {
        l->array[l->_nextIndex++] = item;
    }
}

void* getItemAt(arrayList* l, int index) {
    testIndex(l, index);
    return l->array[index];
}

void* getFirst(arrayList* l) {
    return getItemAt(l, 0);
}

void* getLast(arrayList* l) {
    return getItemAt(l, l->_nextIndex - 1);
}

void* removeItemAt(arrayList* l, int index) {
    testIndex(l, index);
    void* item = getItemAt(l, index);
    for (; index <= l->_nextIndex; index++) {
        l->array[index] = l->array[index + 1];
    }
    l->_nextIndex--;
    return item;
}

void* removeFirst(arrayList* l) {
    return removeItemAt(l, 0);
}

void* removeLast(arrayList* l) {
    return removeItemAt(l, l->_nextIndex - 1);
}

void reverseList(arrayList* l) {
    if (!l) {
        fatalError("arrayList was null");
    }
    if (l->_nextIndex <= 1) {
        return;
    }

    for (int sp = 0, ep = l->_nextIndex - 1; sp < ep; sp++, ep--) {
        void* temp = l->array[sp];
        l->array[sp] = l->array[ep];
        l->array[ep] = temp;
    }
}

void iterateList(arrayList* l, void (*iterator)(void*)) {
    for (int i = 0; i < l->_nextIndex; i++) {
        iterator(l->array[i]);
    }
}

void freeList(arrayList* l) {
    iterateList(l, free);
    free(l->array);
    free(l);
}
