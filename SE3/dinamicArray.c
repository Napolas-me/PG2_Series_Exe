#include "dinamicArray.h"

DinRef_t *dinRefCreate(int initSpace){
    DinRef_t *v = malloc( sizeof *v);
    v->refs = malloc(initSpace *sizeof(MP3Tag_t*));
    v->space = initSpace ;
    v->count = 0;
    return v;
}

void dinRefDelete(DinRef_t *ref){
    free(ref->refs);
    free(ref);
}

void dinRefAdd(DinRef_t *ref, MP3Tag_t *tag);

void dinRefSort(DinRef_t *ref, int (*compar)(const void *, const void *));

MP3Tag_t *dinRefSearch(DinRef_t *ref, void *key, int(*compar)(const void *, const void *)){
   
}

void dinRefScan(DinRef_t *ref, void (*action) (MP3Tag_t*)){
     for(int i = 0; i < ref->space; i++) action(ref->refs[i]);
}

