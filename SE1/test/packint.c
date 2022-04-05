#include <stdio.h>
#include <limits.h>

#define DATA_SIZE (CHAR_BIT - 1)
#define FINAL_MASK (1 << DATA_SIZE)
#define DATA_MASK (~(~0 << DATA_SIZE))
#define SIGN_SIZE 1

int main( int argc, char *argv[] ){
    if( argc != 2 ){
        fprintf( stderr, "Error on arguments;\n"
                         "Usage: %s ouput_filename\n", argv[0] );
        return 1;
    }
    FILE *f = fopen( argv[1], "wb" );
    if( f == NULL ){
        fprintf( stderr, "Fail openning file \"%s\"\n", argv[1] );
        return 2;
    }
    int v;
    while( scanf( "%d", &v ) == 1 ){
        while( v >> (DATA_SIZE - SIGN_SIZE) != 0 &&
               v >> (DATA_SIZE - SIGN_SIZE) != -1 ){
            putc( v & DATA_MASK, f );
            v >>= DATA_SIZE;
        }
        putc( v & DATA_MASK | FINAL_MASK, f );
    }
    fclose( f );
    return 0;
}