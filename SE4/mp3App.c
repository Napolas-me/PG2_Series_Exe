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
//#include "manage.h"
#include "tableRead.h"
#include "stringMan.h"
#include <stdio.h>
#include <ctype.h>

#define INPUT_SIZE 40

char credits[] =
"**********************************\n\n\
\t  Program Made By:\n\n\
\t      Group 14\n\n\
\tPedro Apolinário 47579\n\n\
\tPedro Correia 44705\n\n\
**********************************\n";

void help(){
    printf("------------------------------------------------\n");
    printf("- To get the tags listed by artist use --> a\n");
    printf("- To get the tags listed by titles use --> t\n");
    printf("- To search for a title use --> s <title>\n");
    printf("- To get help use --> h\n");
    printf("- To credits use -> c\n");
    printf("- To quit use --> q\n");
    printf("------------------------------------------------\n");
}

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("ERROR: Not enough arguments!\nUsage: %s <input_File>\n", argv[0]);
        return 0;
    }

    Manage_t *man = manCreate();

    if(tableReadStore(argv[1], man) == -1) return 0;

    manSort(man);

    printf("Enter 'h' for help\n");

    char input[INPUT_SIZE];
    char *input_;

    while(1){
        printf("> ");

        fgets(input, sizeof(input), stdin);
        input_ = cutEndingSpaces(input);

        if(sizeof(*input_) == 1 && *input_ == '\0') continue;
        
        if(input_[1] != ' ' && input_[1] != '\0'){
            help();
            continue;
        }

        switch (tolower(input_[0])){

        case 'q':
            manDelete(man);
            printf("MP3App will no shutdown....\n");
            return 0;

        case 'c':
            printf("%s", credits);
            break;

        case 't':
            manCommand(man, input_);
            //command(&tag, &tagRef, input);
            break;

        case 'a':
            manCommand(man, input_);
            //command(&tag, &tagRef, input_);
            break;

        case 's':
            manCommand(man, input_);
            //command(&tag, &tagRef, input_);
            break;

        case 'h':
        default:
            help();
            break;
        }
    }

    return 0;
}
