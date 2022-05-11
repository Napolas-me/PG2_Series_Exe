/**
 * @file mp3App.c
 * @brief Aplication to read and display information about mp3 tagging
 * @author Group 14
 * @version 0.1
 * @date 11-05-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "mp3.h"
#include "stringMan.h"
#include <stdio.h>

#define INPUT_SIZE 100

char credits[] =
"**********************************\n\n\
\t  Program Made By:\n\n\
\t      Group 14\n\n\
\tPedro Apolinário 47579\n\n\
\tPedro Correia 44705\n\n\
\tTomás Mendonsa 47598\n\n\n\
**********************************\n";

void help(){
    printf("------------------------------------------------\n");
    printf("- To import a file use --> i <FileName>\n");
    printf("- To get the tags listed by artist use --> a\n");
    printf("- To get the tags listed by titles use --> t\n");
    printf("- To search for a title use --> s <title>\n");
    printf("- To get help use --> h\n");
    printf("- To credits use -> c\n");
    printf("- To quit use --> q\n");
    printf("------------------------------------------------\n");
}

int main(){

    printf("Enter 'h' for help\n");

    char input[40];
    char *input_;
    TagArr_t tag;
    TagRef_t tagRef;
    char *fileName;

    int noValue = 1;

    while(1){
        printf("> ");

        scanf("%s", input);
        input_ = cutEndingSpaces(input);
        
        if(input_[1] != ' ' && input_[1] != '\0'){
            help();
            continue;
        }

        switch (tolower(input[0])){

        case 'q':
            printf("MP3App will no shutdown....\n");
            return 0;
        
        case 'i':
            //printf("entered import\n");

            tagArrInit(&tag);

            fileName = getTitle(input_);
            if(tableRead(fileName, &tag) == -1) break;

            tagRefInit(&tag, &tagRef);
            noValue = 0;
            
            break;

        case 'c':
            printf("%s", credits);
            break;

        case 't':
            //printf("entered t\n");

            if(noValue){
                printf("ERROR: No values were imported!\n");
                break;
            }
            command(&tag, &tagRef, input_);
            break;

        case 'a':
            //printf("entered a\n");

            if(noValue){
                printf("ERROR: No values were imported!\n");
                break;
            }
            command(&tag, &tagRef, input_);
            break;

        case 's':
            //printf("entered s\n");

            if(noValue){
                printf("ERROR: No values were imported!\n");
                break;
            }
            command(&tag, &tagRef, input_);
            break;

        case 'h':
        default:
            help();
            break;
        }
    }

    return 0;
}