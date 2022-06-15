#ifndef _ANEX_H_
#define _ANEX_H_

#include "binTree.h"

#define MAX_STR 31
#define MAX_WORD 20

char **splitStrtok( const char str[], int nWords);

TNode *treeToSortedList( TNode *r, TNode *link );

TNode* sortedListToBalancedTree(TNode **listRoot, int n);

int tCount( TNode *r );

#endif
