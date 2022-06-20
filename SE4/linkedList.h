#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "mp3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lNode{	// Nó de lista ligada.
	struct lNode *next;	// Ligação na lista.
	MP3Tag_t *ref;		// Ponteiro para a tag referenciada.
}LNode;

/**
 * Esta função adiciona, a uma lista ligada, um nó, no qual regista o ponteiro para a estrutura indicada
 * por tag. A lista é identificada, no parâmetro hp (head pointer), pelo endereço do ponteiro para o seu
 * primeiro elemento. A inserção na lista dever ser ordenada, com o critério adequado para a sua
 * utilização no comando “f”, de modo a apresentar os dados com a ordem especificada.
 * 
 * @param hp 
 * @param tag 
 */
void lAddRef( LNode **hp, MP3Tag_t *tag );

/**
 * Esta função elimina a lista identificada pelo parâmetro h. Deve libertar a memória dinamicamente
 * alojada para os nós da lista, mas não a das tags referenciadas.
 * 
 * @param h 
 */
void lDelete( LNode *h );

/**
 * Esta função percorre a lista ligada, identificada pelo parâmetro h (head), aplicando a função passada
 * em action a cada uma das tags referenciadas. Esta função é útil, nomeadamente, para apresentar os
 * dados das tags em standard output.
 * 
 * @param h 
 * @param action 
 */
void lScan( LNode *h, void (*action)( MP3Tag_t * ) );

#endif