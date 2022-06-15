/**
 * @file mp3.c
 * @author Group 14
 * @brief 
 * @version 0.1
 * @date 08-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "mp3.h"

void tagArrInit( TagArr_t *data ){
    data->count = 0;
}

void tagRefInit(TagArr_t *data, TagRef_t *ref){
    ref->count = data->count;

    for(int i = 0; i < ref->count; i++){
        ref->refs[i] = &data->tags[i]; 
    }
}

int tagArrAdd( TagArr_t *data, MP3Tag_t *tag ){
    if(data->count + 1 > MAX_TAGS - 1) return -1;

    data->tags[data->count++] = *tag;
    return 0;
}