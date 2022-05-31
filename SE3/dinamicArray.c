#include "dinamicArray.h"

DinRef_t *dinRefCreate(int initSpace);

void dinRefDelete(DinRef_t *ref);

void dinRefAdd(DinRef_t *ref, MP3Tag_t *tag);

void dinRefSort(DinRef_t *ref, int (*compar)(const void *, const void *));

MP3Tag_t *dinRefSearch(DinRef_t *ref, void *key, int(*compar)(const void *, const void *));