#include "manage.h"

Manage_t *manCreate( void ){
    Manage_t *manage = malloc(1 * sizeof(Manage_t));
    
    manage->refA = dinRefCreate(INITSPACE);
    manage->refT = dinRefCreate(INITSPACE);

    return manage;
}

void manDelete( Manage_t *man ){

    dinRefDelete( man->refA );
    dinRefDelete( man->refT );
    free(man);
}

void manAddTag( Manage_t *man, MP3Tag_t *tag ){
    
    dinRefAdd(man->refA , tag);
    dinRefAdd(man->refT , tag);
}

/* **********BEGIN OF COMPARE FUNCTION********** */
int artistCompareV2(const void *t1, const void *t2){
    MP3Tag_t **t1_ = (MP3Tag_t**)t1; 
    MP3Tag_t **t2_ = (MP3Tag_t**)t2;

    int artist = strcmp((*t1_)->artist, (*t2_)->artist);

    if(artist == 0){
        int album = strcmp((*t1_)->album,(*t2_)->album);
        
        if(album == 0) return strcmp((*t1_)->title, (*t2_)->title);

        else return album;
    }
    
    return artist;
}
/* **********END OF COMPARE FUNCTION********** */

void manSort( Manage_t *man ){

    dinRefSort( man->refA , artistCompareV2);
    dinRefSort( man->refT , titleCompare);
}

void printTag(MP3Tag_t* tag){
    printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n", 
        tag->album,
        tag->artist,
        tag->comment,
        tag->genre,
        tag->title,
        tag->track,
        tag->year);
}


void manCommand( Manage_t *man, char *cmdLine ){

    char cmd = tolower(cmdLine[0]);
    char *title;
    MP3Tag_t **res;


    switch (cmd){
    case 'a':
        dinRefScan(man->refA, printTag);//refactoring code to be simpler
        /*
            for(int i = 0; i < man->refA->count; i++){
                printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n", 
                man->refA->refs[i]->album,
                man->refA->refs[i]->artist,
                man->refA->refs[i]->comment,
                man->refA->refs[i]->genre,
                man->refA->refs[i]->title,
                man->refA->refs[i]->track,
                man->refA->refs[i]->year);
            }
        */
        break;
    case 't':
        dinRefScan(man->refT, printTag);
        /*for(int i = 0; i < man->refT->count; i++){
            printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n",
            man->refT->refs[i]->album,
            man->refT->refs[i]->artist,
            man->refT->refs[i]->comment,
            man->refT->refs[i]->genre,
            man->refT->refs[i]->title,
            man->refT->refs[i]->track,
            man->refT->refs[i]->year);
        }*/

        break;
    case 's':
        title = cutEndingSpaces(cmdLine + 2);

        //dinRefScan( man->refT, void (*action)( MP3Tag_t * ));//esta Mal, tens de fazer uma funçao de açao. alias nem faz sentido isto aki

        res = bsearch(title, man->refT->refs, man->refT->space, sizeof(MP3Tag_t*), titleCompare2);

        if(res == NULL){
            printf("Title '%s' not found\n", title);
            break;
        }
        else
        printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n",
            (*res)->album,
            (*res)->artist,
            (*res)->comment,
            (*res)->genre,
            (*res)->title,
            (*res)->track,
            (*res)->year);
        break;
    }

}