#include "binTree.h"

void tAddWordRef( TNode **rp, char *w, MP3Tag_t *tag ){

    if(*rp == NULL){
        TNode *n = malloc(sizeof *n);
        n->word = malloc(strlen(w) * CHAR_BIT);//do i need to malloc string still?
        *n = (TNode){NULL, NULL, strdup(w)};
        lAddRef(&n, tag);
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
    free(r->word);//dunno about this
    free(r);
}

TNode *tSearch( TNode *r, char *w ){
    if(r == NULL) return NULL;

    int cmp = strcmp(w, r->word);
    if(cmp == 0) return r;
    if(cmp < 0) return tSearch(r->left, w);
    return tSearch(r->right, w);
}