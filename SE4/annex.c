#include "annex.h"

char **splitStrtok( const char str[] ){
	char sc[MAX_STR];
	char **words = malloc(MAX_WORD);

	strcpy( sc, str );
	char *p = strtok( sc, " " );
	int i;

	for(i = 0; p != NULL && i < MAX_WORD; i++){
		words[i] = malloc(strlen(p) * CHAR_BIT);
		words[i] = p;
		p = strtok( NULL, " " );
	}

	words[++i] = NULL;

	return words;
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
