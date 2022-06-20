#include "binTree.h"

void tAddWordRef( TNode **rp, char *w, MP3Tag_t *tag ){

    if(*rp == NULL){
        TNode *n = malloc(sizeof *n);
        //n->word = malloc(strlen(w) + 1);
        *n = (TNode){NULL, NULL, strdup(w)};
        lAddRef(&n->list, tag);
        *rp = n;
        return;
    }

    int cmp = strcmp(w, (*rp)->word);

    if(cmp == 0) return;

    if(cmp < 0) tAddWordRef(&(*rp)->left, w, tag);
    else tAddWordRef(&(*rp)->right, w, tag);
}

void tDelete( TNode *r ){
    if(r == NULL) return;

    tDelete(r->left);
    tDelete(r->right);
    lDelete(r->list);
    free(r->word);
    free(r);
}

TNode *tSearch( TNode *r, char *w ){
    if(r == NULL) return NULL;

    int cmp = strcmp(w, r->word);
    if(cmp == 0) return r;
    if(cmp < 0) return tSearch(r->left, w);
    return tSearch(r->right, w);
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

TNode* tBalance(TNode* r){
    r = treeToSortedList(r, NULL);
    return sortedListToBalancedTree(&r,tCount(r));
}