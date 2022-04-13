/**
 * @file readFromFile.c
 * @author Group 14
 * @brief 
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include "stringMan.h"
#include <stdlib.h>
#include <unistd.h>

#define MAX_FIELDS 8
#define FILENAME "outputFile.txt"

int main(int argc, char* argv[]){

    FILE *file = fopen(FILENAME, "w");
    if(file == NULL){
        perror("Error File");
        exit(1);
    }
    char line[255];
    char* field[MAX_FIELDS] = {0};
    int numFields;  
    int atoiValue;

    while(fgets(line, sizeof(line), stdin) != NULL){

        numFields = fields(line, field, MAX_FIELDS);

        if(argc == 1){ // caso sem valores
            for(int i = 0;; i++){
                if(field[i + 1] == 0){
                    printf("%s\n", field[i]);
                    fprintf(file, "%s\n", field[i]);
                    break;
                } 
                else{
                    fprintf(file, "%s;", field[i]);
                    printf("%s;", field[i]); 
                } 
            } 
        }
        else{
            for(int i = 1; i < argc; i++){
                atoiValue = atoi(argv[i]);

                if(atoiValue > numFields || atoiValue <= 0){// numero de input > numero de elementos / numero de input <= zero 
                    if(i == argc - 1){// inserção no meio da linha
                        fprintf(file, "\n");
                        printf("\n");
                    } 
                    else{//inserção no final da linha
                        fprintf(file, ";");
                        printf(";");
                    } 
                } 
                else if(i == argc - 1){// execução normal
                    fprintf(file, "%s\n", field[atoiValue - 1]);
                    printf("%s\n", field[atoiValue - 1]);
                } 
                
                else{// execução normal
                    fprintf(file, "%s;", field[atoiValue - 1]);
                    printf("%s;", field[atoiValue -1]);
                }  
            } 
        }
    }
    
    printf("The file %s contains the output of the program....\n", FILENAME);
   
    return 0;
}