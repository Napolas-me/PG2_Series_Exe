#ifndef _ANEX_H_
#define _ANEX_H_

#include "binTree.h"

#define MAX_STR 1
#define MAX_WORD 20

char **splitStrtok( const char str[] );

void exampleSplit2( const char str[] );

TNode *treeToSortedList( TNode *r, TNode *link );

TNode* sortedListToBalancedTree(TNode **listRoot, int n);

#endif
