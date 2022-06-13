#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

#include "linkedList.h"
#include <limits.h>

typedef struct tNode{			// Nó de árvore binária de pesquisa.
	struct tNode *left, *right;	// Ligação na árvore.
	char *word;					// Palavra associada ao nó – string alojada dinamicamente.
	LNode *list;				// Lista ligada com as referências da palavra.
}TNode;

/**
 *  Esta função adiciona uma referência, para a estrutura indicada por tag, à palavra indicada por w,
 *  localizada numa árvore binária de pesquisa. Se a palavra não existir deve ser criada, fazendo-se o
 *  alojamento dinâmico da respetiva string. A árvore é identificada, no parâmetro rp (root pointer), pelo
 *  endereço do ponteiro para o nó da sua raiz. A inserção na lista de referências, associada à palavra,
 *  dever ser realizada pela função lAddRef. 
 * 
 * @param rp 
 * @param w 
 * @param tag 
 */
void tAddWordRef( TNode **rp, char *w, MP3Tag_t *tag );

/**
 *  Esta função elimina a árvore identificada pelo parâmetro r (root). Deve libertar a memória
 *  dinamicamente alojada para os nós da lista, para as palavras que eles representam e para as respetivas
 *  listas ligadas de referências, utilizando a função lDelete.
 * 
 * @param r 
 */
void tDelete( TNode *r );

/**
 *  Esta função procura, na árvore binária de pesquisa identificada por r (root), a palavra indicada por w,
 *  e retorna o endereço do respetivo nó ou NULL se não existir.
 * 
 * @param r 
 * @param w 
 * @return TNode* 
 */
TNode *tSearch( TNode *r, char *w );
#endif