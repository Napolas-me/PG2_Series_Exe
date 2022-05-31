#include "manage.h"

Manage_t *manCreate( void );

void manDelete( Manage_t *man );

void manAddTag( Manage_t *man, MP3Tag_t *tag );

void manSort( Manage_t *man );

void manCommand( Manage_t *man, char *cmdLine );