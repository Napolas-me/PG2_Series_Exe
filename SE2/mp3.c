/**
 * @file mp3.c
 * @brief 
 * @version 0.1
 * @date 08-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "mp3.h"

void tagArrInit( TagArr_t *data ){
    //data = malloc(sizeof *data); //not sure
    data->count = 0;
    //*data->tags = NULL; //what do i do here
}

int tagArrAdd( TagArr_t *data, MP3Tag_t *tag ){
    if(data->count + 1 > MAX_TAGS - 1) return -1;

    data->tags[data->count++] = *tag;
    return 0;
}

int artistCompare(const MP3Tag_t *t1, const MP3Tag_t *t2){
    return strcmp(*t1->album, *t2->album);
}

int titleCompare(const MP3Tag_t *t1, const MP3Tag_t *t2){
    return strcmp(*t1->title, *t2->title);
}

void setupEnd( TagArr_t *data, TagRef_t *ref ){

    qsort(data->tags, data->count, sizeof *data->tags, artistCompare);
    qsort(*ref->refs,ref->count, sizeof **ref->refs, titleCompare);

}

void command( TagArr_t *data, TagRef_t *ref, char *cmdLine );

int tableRead( char *tableName, TagArr_t *data );
