#include <stdbool.h>

typedef struct {
    //do not change this value manually
    int _currentSize;
    float growthFactor;
    //do not change this value manually
    int _nextIndex;
    void** array;
} arrayList;

arrayList* createArrayList(int startSize, float growthFactor);
void append(arrayList* l, void* item);
void iterateList(arrayList* l, void (*iterator)(void*));
void freeList(arrayList* l, bool freeValues);
void* removeItemAt(arrayList* l, int index);
void* removeFirst(arrayList* l);
void* removeLast(arrayList* l);
int getLastIndex(arrayList* l);
void reverseList(arrayList* l);