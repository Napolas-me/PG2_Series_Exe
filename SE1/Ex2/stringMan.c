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
    CHANGE_LINE = '\n',
	FIELD_SEP = ';'
};

//char FIELD_SEP[MAX_CHAR_VAL] = ";";

char *cutEndingSpaces( char *str ){
	//printf("String:%s:\n", str);
	
	while(*str == SPACE || *str == TAB || *str == CHANGE_LINE) *str++; // skip aos n-elementos que contenham os tipos a eliminar

	if(str[0] == '\0') return str;

	int sizeString = strlen(str) - 1; // tamanho da string aka numero de elementos

	for(int i = sizeString;; i--){
		//printf("%d : %c;\n",i , str[i]);
		if(str[i] != SPACE && str[i] != TAB && str[i] != CHANGE_LINE){
			str[i+1] = '\0';
			break;
		}
	}
	//printf("String:%s:\n", str);
	return str;
}

int fields(char *line, char *ptrs[], int max_fields ){
	
	/*Calcular a quantidade de campos existente */
	
	int fields = 0; // fields existentes em line

	// Contar a quantidade de ";" existentes em line
	
	for(int i = 0;; i++) {
		if(line[i] == FIELD_SEP) fields++;
		if(line[i] == '\0'){
			fields++;
			break;
		}
	}
		
	/* Separar os campos */
	//char sep[strlen(line)];

	// i --> iteraçao de line
	// j --> iteraçao de ptrs
	int last = 0;

	for(int i = 0, j = 0; j < max_fields; i++){
		if(line[i] == FIELD_SEP || line[i] == '\0'){
			line[i] = '\0';
			ptrs[j] = cutEndingSpaces(line + last);
			last = i + 1;
			j++;
		}
	}
	return fields;
}
