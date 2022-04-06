#include "stringMan.h"
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
		if(str[i] != SPACE  && str[i] != TAB && str[i] != CHANGE_LINE){
			str[i+1] = '\0';
			break;
		}
	}	

	return str;
}

int fields(char *line, char *ptrs[], int max_fields ){
    
}
