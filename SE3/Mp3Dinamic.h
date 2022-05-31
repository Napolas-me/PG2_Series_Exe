#ifndef _DINAMIC_ARRAY_H_
#define _DINAMIC_ARRAY_H_

#include "mp3.h"

typedef struct{
	int space; //Quantidade de elementos alojados no campo refs
	int count; // Quantidade de elementos preenchidos no campo refs
	Mp3Tag_t **refs; //Ponteiros para array de ponteiros para tag; alojamento dinamico
}DinRef_t;

Dinref *dinRefCreate(int initSpace);

void dinRefDelete(DinRef_t *ref);

void dinRefAdd(Dinref_t *ref, Mp3Tag_t *tag);

void dinRefSort(DinRef *ref, int (*compar)(const void *, const void *));

Mp3Tag_t *dinRefSearch(DinRef_t *ref, void key, int(*compar)(const void *, const void *));

#endif
