#include "binTree.h"

#define MAX_STR 1
#define MAX_WORD 1

void exampleSplit1( const char str[] ){
	char sc[MAX_STR];
	strcpy( sc, str );
	char *p = strtok( sc, " \t\n" );
	while( p != NULL ){
		printf( "%s\n", p );
		p = strtok( NULL, " \t\n" );
	}
}

void exampleSplit2( const char str[] ){
	char word[MAX_WORD];
	int i = 0, n;
	while( sscanf( str + i, "%s%n", word, &n ) == 1 ){
		printf( "%s\n", word );
		i += n;
	}
}

TNode *treeToSortedList( TNode *r, TNode *link ){
	TNode * p;
	if( r == NULL ) return link;
	p = treeToSortedList( r->left, r );
	r->left = NULL;
	r->right = treeToSortedList( r->right, link );
	return p;
}

TNode* sortedListToBalancedTree(TNode **listRoot, int n) {
	if( n == 0 )
		return NULL;
	TNode *leftChild = sortedListToBalancedTree(listRoot, n/2);
	TNode *parent = *listRoot;
	parent->left = leftChild;
	*listRoot = (*listRoot)->right;
	parent->right = sortedListToBalancedTree(listRoot, n-(n/2 + 1) );
	return parent;
}
