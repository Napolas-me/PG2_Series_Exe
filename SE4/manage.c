#include "manage.h"

Manage_t *manCreate( void ){
    Manage_t *manage = malloc(1 * sizeof(Manage_t));
    
    manage->refA = dinRefCreate(INITSPACE);
    manage->refT = dinRefCreate(INITSPACE);
    manage->bst = NULL;// arvore vazia

    return manage;
}

void freeMp3(MP3Tag_t* tag){
    free(tag);
}

void manDelete( Manage_t *man ){
    dinRefScan(man->refA, freeMp3);
    dinRefDelete( man->refA );
    dinRefDelete( man->refT );
    tDelete(man->bst);
    free(man);
}

void manAddTag( Manage_t *man, MP3Tag_t *tag ){
    
    dinRefAdd(man->refA , tag);
    dinRefAdd(man->refT , tag);
    
    char str[MAX_STR];
    strcpy(str, tag->title);

    char *p = strtok(str, " ");
    while(p != NULL){
        tAddWordRef(&man->bst, p, tag);
        p = strtok(NULL, " ");
    } 
}

/**********************************************************************/
/************************** COMPARE FUNCS *****************************/
/**********************************************************************/

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

int titleCompare(const void *t1, const void *t2){
    MP3Tag_t **t1_ = (MP3Tag_t**)t1;
    MP3Tag_t **t2_ = (MP3Tag_t**)t2;

    int title = strcmp((*t1_)->title, (*t2_)->title);

    if(title == 0){
        int artist = strcmp((*t1_)->artist, (*t2_)->artist);

        if(artist == 0) return strcmp((*t1_)->album, (*t2_)->album);

        else return artist;
    }

    return title;
}

int artistCompare(const void *t1, const void *t2){
    const MP3Tag_t *t1_ = t1; 
    const MP3Tag_t *t2_ = t2;

    int artist = strcmp(t1_->artist, t2_->artist);

    if(artist == 0){
        int album = strcmp(t1_->album, t2_->album);
        
        if(album == 0) return strcmp(t1_->title, t2_->title);

        else return album;
    }
    
    return artist;
}

int titleCompare2(const void *t1, const void *t2){

    MP3Tag_t **t2_ = (MP3Tag_t**)t2;

    return strcmp(t1, (*t2_)->title);
}
/**********************************************************************/
/************************** COMPARE FUNCS *****************************/
/**********************************************************************/

void manSort( Manage_t *man ){

    dinRefSort( man->refA , artistCompareV2);
    dinRefSort( man->refT , titleCompare);

    man->bst = tBalance(man->bst);
}

void setupEnd( TagArr_t *data, TagRef_t *ref ){
    tagRefInit(data, ref);

    qsort(data->tags, data->count, sizeof(MP3Tag_t), artistCompare);
    qsort(ref->refs, ref->count, sizeof(MP3Tag_t*), titleCompare);
}

void command( TagArr_t *data, TagRef_t *ref, char *cmdLine ){

    char cmd = tolower(cmdLine[0]);
    setupEnd(data, ref);
    char *title;
    MP3Tag_t **res;

    switch (cmd){
    case 'a':
        for(int i = 0; i < data->count; i++){
            printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n", 
            data->tags[i].album, 
            data->tags[i].artist, 
            data->tags[i].comment, 
            data->tags[i].genre, 
            data->tags[i].title, 
            data->tags[i].track, 
            data->tags[i].year);
        }

        break;
    case 't':
        for(int i = 0; i < ref->count; i++){
            printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n",
            ref->refs[i]->album,
            ref->refs[i]->artist,
            ref->refs[i]->comment,
            ref->refs[i]->genre,
            ref->refs[i]->title,
            ref->refs[i]->track,
            ref->refs[i]->year);
        }

        break;
    case 's':
        title = cutEndingSpaces(cmdLine + 2);

        res = bsearch(title, ref->refs, ref->count, sizeof(MP3Tag_t*), titleCompare2);

        if(res == NULL){
            printf("Title '%s' not found\n", title);
            break;
        }
        else printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n",
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

int splitStrtok( const char str[], char **words){
	char sc[MAX_STR];
    char **aux = malloc(1);
	int nWords = 0;

	strcpy( sc, str );
	char *p = strtok(sc, " ");
	//int i;

	for(int i = 0; p != NULL; i++){
		aux[i] = strdup(p);
		nWords++;
        p = strtok(NULL, " ");
	}

    words = aux;
	return nWords;
}

void manCommand( Manage_t *man, char *cmdLine ){
    char cmd = tolower(cmdLine[0]);
    char *title;
    char **words;
    int nWords;
    MP3Tag_t *res;

    switch (cmd){
    case 'a':
        dinRefScan(man->refA, printTag);
        break;

    case 't':
        dinRefScan(man->refT, printTag);
        break;

    case 's':
        title = cutEndingSpaces(cmdLine + 2);
        res = dinRefSearch(man->refT, title, titleCompare2); 
        
        if(res == NULL){
            printf("Title '%s' not found\n", title);
            break;
        }
        else
        printf("%-31s; %-31s; %-31s; %-2d; %-31s; %-2d; %-4d\n",
            res->album,
            res->artist,
            res->comment,
            res->genre,
            res->title,
            res->track,
            res->year);
        break;
    
    case 'f':
        nWords = splitStrtok(cmdLine + 2, words);
        TNode *r;

        for(int i = 0; i < nWords; i++){
            r = tSearch(man->bst, words[i]);
            if(r == NULL) printf("A palavra %s não consta em nenhum titulo!", words[i]);
            else lScan(r->list, printTag);

            free(words[i]);
        }

        free(words);
        break;
    }
}
