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
        ref->refs[i] = data->tags; 
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

    MP3Tag_t **t1_ = (MP3Tag_t**)t1;
    MP3Tag_t **t2_ = (MP3Tag_t**)t2;

    return strcmp((*t1_)->title, (*t2_)->title);
    
}

void setupEnd( TagArr_t *data, TagRef_t *ref ){

    //qsort(data->tags, data->count, sizeof *data->tags, artistCompare); //wrong
    //qsort(ref->refs,ref->count, sizeof *ref->refs, titleCompare); //wrong

    qsort(data->tags, data->count, sizeof(MP3Tag_t), artistCompare);
    qsort(ref->refs,ref->count, sizeof(MP3Tag_t*), titleCompare);

}

char* getTitle(char* str){
    int i;
    char* title;

    for(i = 2; str[i] != '\0'; i++){
        title[i-2] = str[i];
    } 

    title[i-2] = '\0';
    return title;
}

void command( TagArr_t *data, TagRef_t *ref, char *cmdLine ){

    char cmd = tolower(cmdLine[0]);
    setupEnd(data, ref);
    char *title;
    MP3Tag_t *res;

    switch (cmd){
    case 'a':
        for(int i = 0; i < data->count; i++){
            printf("%s; %s; %s; %d; %s; %c; %c\n", 
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
            printf("%s; %s; %s; %d; %s; %c; %c\n",
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
        title = cutEndingSpaces(getTitle(cmdLine));

        res = bsearch(title, ref->refs, ref->count, sizeof(MP3Tag_t*), titleCompare2);

        if(res == NULL){
            printf("ERROR: Title '%s' not found\n", title);
            break;
        }
        else printf("%s; %s; %s; %d; %s; %c; %c\n",
            res->album,
            res->artist,
            res->comment,
            res->genre,
            res->title,
            res->track,
            res->year);
        break;
    }

}

int tableRead( char *tableName, TagArr_t *data ){
    FILE *f = fopen(tableName,"r");
    char buffer[1024];
    char *field[MAX_PARAMS];
    
    if(f == NULL){
        perror("Error opening file");
        return -1;
    }

    int line = 1;
    while(fgets(buffer, sizeof(buffer), f) != NULL){
        if(line == 1){
            line++;
            continue;   
        } 

        fields(buffer, field, MAX_PARAMS);
        
        strcpy(data->tags[data->count].title, field[0]);
        strcpy(data->tags[data->count].artist, field[1]);
        strcpy(data->tags[data->count].album, field[2]);
        data->tags[data->count].year = atoi(field[3]);
        strcpy(data->tags[data->count].comment, field[4]);
        data->tags[data->count].track = field[5][0];
        data->tags[data->count].genre = field[6][0];
        data->count++;
    }

    return 0;
}
