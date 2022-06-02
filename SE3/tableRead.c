/**
 * @file tableRead.c
 * @brief 
 * @version 0.1
 * @date 31-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "tableRead.h"

int tableReadStore( char *tableName, Manage_t *man ){

    FILE *f = fopen(tableName,"r");
    char buffer[1024];
    char *field[MAX_PARAMS];
    MP3Tag_t *tag;
    
    if(f == NULL){
        perror("Error opening file");
        return -1;
    }
    
    fgets(buffer, sizeof(buffer), f);

    while(fgets(buffer, sizeof(buffer), f) != NULL){

        fields(buffer, field, MAX_PARAMS);
        tag = malloc(sizeof(MP3Tag_t));
        
        strcpy(tag->title, field[0]);
        strcpy(tag->artist, field[1]);
        strcpy(tag->album, field[2]);
        tag->year = atoi(field[3]);
        strcpy(tag->comment, field[4]);
        tag->track = atoi(field[5]);
        tag->genre = atoi(field[6]);

        manAddTag(man, tag);
    }

    return 0;
}