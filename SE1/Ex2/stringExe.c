#include "stringMan.h"
#include <stdio.h>

char* simpleTestString = "\t Teste\n  ";

int main(int argc, char* argv[]){
    char* returnTest1 = 0;

    returnTest1 = cutEndingSpaces(simpleTestString);
    printChanges(simpleTestString, returnTest1);
    return 0;
}

void printChanges(char* ini, char* change){
    printf("%s --> ", ini);
    printf("%s\n", change);   
}