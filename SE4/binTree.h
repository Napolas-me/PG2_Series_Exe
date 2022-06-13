#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_

#include "linkedList.h"

typedef struct tNode{			// Nó de árvore binária de pesquisa.
	struct tNode *left, *right;	// Ligação na árvore.
	char *word;					// Palavra associada ao nó – string alojada dinamicamente.
	LNode *list;				// Lista ligada com as referências da palavra.
}TNode;

#endif