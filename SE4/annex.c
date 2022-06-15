#include "annex.h"

char **splitStrtok( const char str[], int *nWords){
	char sc[MAX_STR];
	char **words = malloc(1);
	*nWords = 0;

	strcpy( sc, str );
	char *p = strtok(sc, " ");
	//int i;

	for(int i = 0; p != NULL; i++){
		words[i] = strdup(p);
		*nWords++;
		words = realloc(words, i + 2);
		p = strtok(NULL, " ");
	}
	return words;
}

void freeWords(){

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

int tCount( TNode *r ){
	return r == NULL ? 0 : 1 + tCount( r->left ) + tCount( r->right );
}
