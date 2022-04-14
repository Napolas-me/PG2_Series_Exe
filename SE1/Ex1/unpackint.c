#include <stdio.h>
#include <limits.h>
#include "func.h"

#define DATA_SIZE (CHAR_BIT - 1)
#define FINAL_MASK (1 << DATA_SIZE)
#define DATA_MASK (~(~0 << DATA_SIZE))
#define SIGN_SIZE 1

int main(int argc, char* argv[]){
    
    if(argc != 2){
        fprintf( stderr, "Error on arguments;\n"
                        "Usage: %s input_filename\n", argv[0] );
                        return 1;
    }

    FILE *f = fopen(argv[1], 'r');

    if(f == NULL){
        fprintf( stderr, "Fail openning file \"%s\"\n", argv[1] );
        return 2;
    }

    /*
     *
     *  NEW CODE
     *  
     */
    int v;
    int last;
    int result = 0;
    while( scanf( "%x", &v ) == 1 ){
       /* last = ( (v >> (DATA_SIZE +1) ) & 0x1 );
        int counter = 0;
        while ( !last ){
            result |= ( (v & DATA_MASK) << (DATA_SIZE * counter) );
            counter ++;
        }
        result <<= DATA_SIZE * counter;
        result |= signExtend();*/
        printf("%x", v);
    }
    
    fclose(f);
    return 0;
}