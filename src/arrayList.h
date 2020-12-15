#ifndef ARRAY_LIST_L
#define ARRAY_LIST_L
#include <stdbool.h>

typedef struct {
    //the number of items the list can currently hold
    //do not change this value manually
    int _currentCapacity;
    float growthFactor;
    //do not change this value manually
    int _nextIndex;
    void** array;
} arrayList;

arrayList* createArrayList();
void appendToAl(arrayList* l, void* item);
void* insertItemAt(arrayList* l, int index, void* item);
void* getItemAt(arrayList* l, int index);
void* getFirstItem(arrayList* l);
void* getLastItem(arrayList* l);
void* removeItemAt(arrayList* l, int index);
void* removeFirstItem(arrayList* l);
void* removeLastItem(arrayList* l);
int getLastIndexAl(arrayList* l);
int getSize(arrayList* l);
void reverseAl(arrayList* l);
void iterateListItems(arrayList* l, void (*iterator)(void*));
void freeAl(arrayList* l, bool freeValues);
void clearAl(arrayList* l, bool freeValues);

#endif