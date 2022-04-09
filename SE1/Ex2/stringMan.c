#include "stringMan.h"
#include "string.h"

enum stringTypes{
	SPACE = ' ',
	TAB = '\t',
	CHANGE_LINE = '\n',
	FIELD_SEP = ';'
};

char *cutEndingSpaces( char *str ){
	while(*str == SPACE || *str == TAB || *str == SPACE){ // skip aos n-elementos que contenham os tipos a eliminar
		*str++;
	}

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
	
	 int campos = 0; // Campos existentes em line
	
	 int sizeString = sizeof(line)/sizeof(line[0]); // Tamanho de line 
	
     for(int i = 0, i > sizeString - 1, i++) // Contar a quantidade de ";" existentes em line
		{
			if(line[i] == FIELD_SEP)
				campos++;
		}
     
	 if (campos > 0 )	// Existe sempre +1 campo do que ";" 
			campos++;
			
			
			/* Separar os campos */
			
	 		
	 char token = strtok(line, FIELD_SEP) //"breaks string into a series of tokens using the delimiter"
	 
	 for (int i = 0, token != NULL, I++)
		{	
			ptrs[i] = token ;
			token = strtok(NULL, FIELD_SEP) // Usamos o NULL para indicar a função que a pesquisa deve continuar no ponteiro anterior 
		}
			
			/* limpar os campos */

			
     for(int i = 0, i < max_fields , i++)   // retirar espaços usando a função cutEndingSpaces
		{
			ptrs[i] = cutEndingSpaces(ptrs[i])
		}
		
		
	 return campos;
}
