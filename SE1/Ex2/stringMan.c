/**
 * @file stringMan.c
 * @author Group 14
 * @brief File holding the functions used in exe2
 * @version 0.1
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "stringMan.h"
#include <string.h>
#include <stdio.h>

#define MAX_CHAR_VAL 2

enum stringTypes{
    SPACE = ' ',
    TAB = '\t',
    CHANGE_LINE = '\n',
	FIELD_SEP = ';'
};
/**
 * @brief Function to cut the ending spaces from a pointer to a string passed by argument
 * 
 * @param str string with spaces
 * @return pointer to the string with ending spaces removed 
 */
char *cutEndingSpaces( char *str ){
	
	while(*str == SPACE || *str == TAB || *str == CHANGE_LINE) *str++; // skip aos n-elementos que contenham os tipos a eliminar

	if(str[0] == '\0') return str;

	int sizeString = strlen(str) - 1; // tamanho da string aka numero de elementos

	for(int i = sizeString;; i--){
		if(str[i] != SPACE && str[i] != TAB && str[i] != CHANGE_LINE){
			str[i+1] = '\0';
			break;
		}
	}
	return str;
}
/**
 * @brief Function to separate strings from a line.
 * The separator element is ';'
 * 
 * @param line line to evaluate
 * @param ptrs array of pointers with diferent starting points of line
 * @param max_fields max number of fields in ptrs
 * @return number of real fields in line 
 */
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

	// i --> iteraçao de line
	// j --> iteraçao de ptrs
	int last = 0;

	for(int i = 0, j = 0; j < max_fields || i + 1 < sizeof(line); i++){
		if(line[i] == FIELD_SEP || line[i] == '\0'){
			line[i] = '\0';
			ptrs[j] = cutEndingSpaces(line + last);
			last = i + 1;
			j++;
		}
	}
	return fields;
}
