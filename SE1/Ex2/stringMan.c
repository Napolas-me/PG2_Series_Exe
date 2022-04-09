#include "stringMan.h"
#include <string.h>

enum stringTypes{
	SPACE = ' ',
	TAB = '\t',
	CHANGE_LINE = '\n',
	FIELD_SEP = ';'
};

char *cutEndingSpaces( char *str ){
	while(*str == SPACE || *str == TAB || *str == SPACE) *str++; // skip aos n-elementos que contenham os tipos a eliminar

	if(str[0] == '\0') return str;
	
	int sizeString = sizeof(str)/sizeof(str[0]); // tamanho da string aka numero de elementos

	for(int i = sizeString - 1;; i--){
		if(str[i] != SPACE || str[i] != TAB || str[i] != CHANGE_LINE){
			str[i+1] = '\0';
			break;
		}
	}	

	return str;
}

int fields(char *line, char *ptrs[], int max_fields ){
	
	/*Calcular a quantidade de campos existente */
	
	int fields = 0; // fields existentes em line
	
	//int sizeString = sizeof(line)/sizeof(*line); // Tamanho de line

	// Contar a quantidade de ";" existentes em line
	//comprimi a contagem para dentro de um unico for
	/*
	for(int i = 0; i <= sizeString; i++) {
		if(line[i] == FIELD_SEP || line[i] == '\0') fields++;
	}*/

	// Existe sempre +1 campo do que ";"
	// Em principio esta corrigido no if em cima
	// if (fields > 0) fields++;
		
	/* Separar os campos */
		
	char *token = strtok(line, FIELD_SEP); //"breaks string into a series of tokens using the delimiter"
	//fields++;
	
	for(int i = 0; token != NULL; i++){	
		fields++;
		ptrs[i] = cutEndingSpaces(token);
		token = strtok(NULL, FIELD_SEP); // Usamos o NULL para indicar a função que a pesquisa deve continuar no ponteiro anterior 
	}
		
	/* limpar os campos */

	// retirar espaços usando a função cutEndingSpaces
	//reduçao de numero de FORs	
	//for(int i = 0; i < max_fields ; i++) ptrs[i] = cutEndingSpaces(ptrs[i]);
	
	return fields;
}
