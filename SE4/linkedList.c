#include "linkedList.h"

int titleComparelinked(const void *t1, const void *t2){
    MP3Tag_t *t1_ = (MP3Tag_t*)t1;
    MP3Tag_t *t2_ = (MP3Tag_t*)t2;

    int title = strcmp(t1_->title, t2_->title);

    if(title == 0){
        int artist = strcmp(t1_->artist, t2_->artist);

        if(artist == 0) return strcmp(t1_->album, t2_->album);

        else return artist;
    }
    return title;
}

void lAddRef( LNode **hp, MP3Tag_t *tag ){
    LNode *p, *a;

    for(p = *hp; p != NULL && titleComparelinked(tag, p->ref) > 0; a = p, p = p->next);

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