#include "dinamicArray.h"

#define BLOCK_SIZE 8 // not so sure about this but ok

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

void dinRefScan(DinRef_t *ref, void (*action) (MP3Tag_t*)){
     for(int i = 0; i < ref->count; i++) action(ref->refs[i]);
}

void dinRefSort (DinRef_t *ref, int (*compar)(const void *, const void*)){
	qsort(ref->refs, ref->count, sizeof(MP3Tag_t*), compar);
}

void dinRefAdd (DinRef_t *ref, MP3Tag_t *tag){
	if (ref->count == ref->space) ref->refs = realloc(ref->refs, (ref->space += BLOCK_SIZE) * sizeof *ref);
	ref->refs[ref->count++] = tag;
}

MP3Tag_t *dinRefSearch (DinRef_t *ref, void *key, int (*compar)(const void *, const void*)){
    MP3Tag_t **tag = bsearch(key, ref->refs, ref->count, sizeof(MP3Tag_t*), compar);
	return *tag;	
}