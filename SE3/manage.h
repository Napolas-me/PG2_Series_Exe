#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "dinamicArray.h"

#define INITSPACE 4

typedef struct{
	DinRef_t *refA;
	DinRef_t *refT;
}Manage_t;

Manage_t *manCreate( void );

void manDelete( Manage_t *man );

void manAddTag( Manage_t *man, MP3Tag_t *tag );

void manSort( Manage_t *man );

void manCommand( Manage_t *man, char *cmdLine );

#endif
