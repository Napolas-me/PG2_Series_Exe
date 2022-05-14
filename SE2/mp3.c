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

int titleCompare2(const void *t1, const void *t2){

    MP3Tag_t **t2_ = (MP3Tag_t**)t2;

    return strcmp(t1, (*t2_)->title);
    
}

void setupEnd( TagArr_t *data, TagRef_t *ref ){
    
    //qsort(data->tags, data->count, sizeof *data->tags, artistCompare); //wrong
    //qsort(ref->refs,ref->count, sizeof *ref->refs, titleCompare); //wrong
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
            printf("%-31s; %-31s; %-31s; %-4d; %-30s; %-2c; %-2c\n", 
            data->tags[i].title, 
            data->tags[i].artist, 
            data->tags[i].album, 
            data->tags[i].year, 
            data->tags[i].comment, 
            data->tags[i].track, 
            data->tags[i].genre);
        }

        break;
    case 't':
        for(int i = 0; i < ref->count; i++){
            printf("%-31s; %-31s; %-31s; %-4d; %-30s; %-2c; %-2c\n",
            ref->refs[i]->title,
            ref->refs[i]->artist,
            ref->refs[i]->album,
            ref->refs[i]->year,
            ref->refs[i]->comment,
            ref->refs[i]->track,
            ref->refs[i]->genre);
        }

        break;
    case 's':
        title = cutEndingSpaces(cmdLine + 2);

        res = bsearch(title, ref->refs, ref->count, sizeof(MP3Tag_t*), titleCompare2);

        if(res == NULL){
            printf("Title '%s' not found\n", title);
            break;
        }
        else printf("%-31s; %-31s; %-31s; %-4d; %-30s; %-2c; %-2c\n",
            (*res)->title,
            (*res)->artist,
            (*res)->album,
            (*res)->year,
            (*res)->comment,
            (*res)->track,
            (*res)->genre);
        break;
    }

}

int tableRead( char *tableName, TagArr_t *data ){
    FILE *f = fopen(tableName,"r");
    char buffer[1024];
    char *field[MAX_PARAMS];
    MP3Tag_t tag;
    
    if(f == NULL){
        perror("Error opening file");
        return -1;
    }
    fgets(buffer, sizeof(buffer), f);

    while(fgets(buffer, sizeof(buffer), f) != NULL){

        fields(buffer, field, MAX_PARAMS);
        
        strcpy(tag.title, field[0]);
        strcpy(tag.artist, field[1]);
        strcpy(tag.album, field[2]);
        tag.year = atoi(field[3]);
        strcpy(tag.comment, field[4]);
        tag.track = field[5][0];
        tag.genre = field[6][0];

        if(tagArrAdd(data, &tag) == -1) return -1;
    }

    return 0;
}
