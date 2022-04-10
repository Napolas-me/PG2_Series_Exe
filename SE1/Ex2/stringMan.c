#include "stringMan.h"
#include <string.h>
#include <stdio.h>

//#define	SPACE ' '
//#define	TAB '\t'
//#define	CHANGE_LINE '\n'
//#define	FIELD_SEP ';'

#define MAX_CHAR_VAL 2

enum stringTypes{
    SPACE = ' ',
    TAB = '\t',
    CHANGE_LINE = '\n'
};

char FIELD_SEP[MAX_CHAR_VAL] = ";";

char *cutEndingSpaces( char *str ){
	
	while(*str == SPACE || *str == TAB || *str == CHANGE_LINE) *str++; // skip aos n-elementos que contenham os tipos a eliminar

	if(str[0] == '\0') return str;

	int sizeString = strlen(str) - 1; // tamanho da string aka numero de elementos

	for(int i = sizeString;; i--){
		printf("%d : %c;\n",i , str[i]);
		if(str[i] != SPACE && str[i] != TAB && str[i] != CHANGE_LINE){
			str[i+1] = '\0';
			break;
		}
	}

	return str;
}

int fields(char *line, char *ptrs[], int max_fields ){
	
	/*Calcular a quantidade de campos existente */
	
	int fields = 0; // fields existentes em line
	
	int sizeString = sizeof(line)/sizeof(*line); // Tamanho de line

	// Contar a quantidade de ";" existentes em line
	
	for(int i = 0; i <= sizeString; i++) {
		if(line[i] == FIELD_SEP[0] || line[i] == '\0') fields++;
	}
		
	/* Separar os campos */
		
	char *token = strtok(line, FIELD_SEP); //"breaks string into a series of tokens using the delimiter"
	
	for(int i = 0; i < max_fields; i++){	
		ptrs[i] = cutEndingSpaces(token);
		token = strtok(NULL, FIELD_SEP); // Usamos o NULL para indicar a função que a pesquisa deve continuar no ponteiro anterior 
	}
	
	return fields;
}
