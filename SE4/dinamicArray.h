/**
 * @file dinamicArray.h
 * @brief 
 * @version 0.1
 * @date 31-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _DINAMIC_ARRAY_H_
#define _DINAMIC_ARRAY_H_

#include "mp3.h"
#include <stdlib.h>

typedef struct{
	int space; //Quantidade de elementos alojados no campo refs
	int count; // Quantidade de elementos preenchidos no campo refs
	MP3Tag_t **refs; //Ponteiros para array de ponteiros para tag; alojamento dinamico
}DinRef_t;

/**
 * 	Esta função cria, em alojamento dinâmico, e retorna, um descritor de um array dinâmico de ponteiros
 *	para tags, alojando a quantidade de elementos indicada por initSpace. O descritor é iniciado no
 *	estado vazio.
 * 
 * @param initSpace 
 * @return DinRef_t* 
 */
DinRef_t *dinRefCreate(int initSpace);
/**
 * Esta função elimina o array dinâmico de referências, indicado por ref. Deve libertar a memória
dinamicamente alojada para o descritor e para o array, mas não a das tags referenciadas. Estas podem
estar associadas a vários arrays de referências, pelo que não pertencem a nenhum deles, devendo ser
eliminadas explicitamente. Para isso, pode ser usada a função dinRefScan especificada abaixo.
 * 
 * @param ref 
 */
void dinRefDelete(DinRef_t *ref);

/**
 *Esta função adiciona ao descritor, indicado por ref, o ponteiro para a estrutura indicada por tag,
previamente alojada e preenchida. Quando necessário, redimensiona o array, utilizado a função
realloc de biblioteca. O redimensionamento deve ser realizado em blocos de vários elementos.
 * 
 * @param ref 
 * @param tag 
 */
void dinRefAdd(DinRef_t *ref, MP3Tag_t *tag);

/**
 *Esta função ordena o array de referências, pertencente ao descritor indicado por ref, com o critério
implementado pela função de comparação passada em compar, compatível com a especificação da
função qsort, de biblioteca, que deve ser usada para ordenar o array de referências.
 * 
 * @param ref 
 * @param compar 
 */

void dinRefSort(DinRef_t *ref, int (*compar)(const void *, const void *));

/**
 * Esta função realiza pesquisa binária no array de referências, pertencente ao descritor indicado por
ref, aplicando a chave de pesquisa key, com o critério implementado pela função de comparação
passada em compar, compatível com a especificação da função bsearch, de biblioteca, que deve
ser usada para a pesquisa. A função retorna o endereço da tag encontrada ou NULL no caso de
insucesso. Assume-se que o array foi previamente ordenado.
 * 
 * @param ref 
 * @param key 
 * @param compar 
 * @return MP3Tag_t* 
 */
MP3Tag_t *dinRefSearch(DinRef_t *ref, void *key, int(*compar)(const void *, const void *));

/**
 * Esta função percorre o array de referências, pertencente ao descritor indicado por ref, do índice 0
para o mais alto, aplicando a função passada em action a cada uma das tags referenciadas. Esta
função é útil, por exemplo, para apresentar os dados das tags em standard output ou para libertar a
memória ocupada pelas tags.
 * 
 * @param ref 
 * @param action 
 */
void dinRefScan( DinRef_t *ref, void (*action)( MP3Tag_t * ) );

#endif
