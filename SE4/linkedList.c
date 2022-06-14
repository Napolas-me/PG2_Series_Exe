#include "linkedList.h"

/**
 * 
 * FIFO
 * 
 */

void lAddRef( LNode **hp, MP3Tag_t *tag ){
    LNode *p, *a;

    for(p = *hp; p != NULL /*&& do i do something here, maybe strcmp(tag->title, p->ref->title) > 0*/ ; a = p, p = p->next);

    LNode *n = malloc(sizeof *n);
    n->ref = tag;
    n->next = p;

    if(p == *hp) *hp = n;
    else a->next = n;

}

void lDelete( LNode *h ){
    LNode *p = h, *a;
    while(p != NULL){
        a = p->next;
        free(p);
        p = a;
    }
}

void lScan( LNode *h, void (*action)( MP3Tag_t * ) ){

    LNode *p = h, *a;
    while(p != NULL){
        a = p->next;
        action(p->ref);
        p = a;
    }
}