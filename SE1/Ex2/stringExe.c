#include "stringMan.h"
#include <stdio.h>

#define MAX_SIZE 4

void printChanges(char* ini, char* change);

char simpleTestString[] = " palavras do quinto campo 1234\n";
char complexExample[] = "primeiro campo;; terceiro campo \t; ; palavras do quinto campo 1234\n";

int main(int argc, char* argv[]){
    char* returnTest1 = 0;
    char* returnTest2[MAX_SIZE];

    returnTest1 = cutEndingSpaces(simpleTestString);
    printChanges(simpleTestString, returnTest1);

    /*int numFields = fields(complexExample, returnTest2, MAX_SIZE);

    for(int i = 0; i < MAX_SIZE; i++) printf("ptrs[%d] = %s\n", i, returnTest2[i]);
    printf("The number of fields was %d", numFields);*/

    return 0;
}

void printChanges(char* ini, char* change){
    printf("[%s]-->", ini);
    printf("(%s)\n", change);   
}