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
}

int tagArrAdd( TagArr_t *data, MP3Tag_t *tag ){
    if(data->count + 1 > MAX_TAGS - 1) return -1;

    data->tags[data->count++] = *tag;
    return 0;
}

int artistCompare(const void *t1, const void *t2){
    return strcmp(((MP3Tag_t*) t1)->album, ((MP3Tag_t*) t2)->album);
}

int titleCompare(const void **t1, const void **t2){
    return strcmp(((MP3Tag_t *)(*t1))->title, ((MP3Tag_t *)(*t2))->title);
}

void setupEnd( TagArr_t *data, TagRef_t *ref ){

    //qsort(data->tags, data->count, sizeof *data->tags, artistCompare); //wrong
    //qsort(ref->refs,ref->count, sizeof *ref->refs, titleCompare); //wrong

    qsort(data->tags, data->count, sizeof(MP3Tag_t), artistCompare);
    qsort(ref->refs,ref->count, sizeof(MP3Tag_t*), titleCompare);

}

void command( TagArr_t *data, TagRef_t *ref, char *cmdLine );

int tableRead( char *tableName, TagArr_t *data );
