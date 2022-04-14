#include <stdio.h>
#include <limits.h>
//#include "func.h"

#define DATA_SIZE (CHAR_BIT - 1)
#define FINAL_MASK (1 << DATA_SIZE)
#define DATA_MASK 0x7F//(~(~0 << DATA_SIZE))
#define SIGN_SIZE 1
#define LAST_DATA_MASK 0xF

int main(int argc, char* argv[]){
    
    if(argc != 2){
        fprintf( stderr, "Error on arguments;\n"
                        "Usage: %s input_filename\n", argv[0] );
                        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if(f == NULL){
        fprintf( stderr, "Fail openning file \"%s\"\n", argv[1] );
        return 2;
    }

    /*
     *
     *  NEW CODE
     *  
     */

    printf("before while, checkpoint 1\n");

    int v;
    int last;
    int result = 0;
    int count=0;
    int counter2 = 0;
    do
    {
        // Taking input single character at a time
        char c = fgetc(f);
 
        // Checking for end of file
        if (feof(f))
            break ;

        printf("%d-> char: %c dec: %d hex: %x\n", count, c, c, c);
        

        last = ( (c >> (DATA_SIZE) & 0x1 ) );
        printf("the last is %x \n", last);
        
        if (!last ){
            int chungus = ( (c & DATA_MASK) << (DATA_SIZE * counter2) );
            printf("\nchungus is %x\n", chungus);
            result = result | chungus;
            counter2 ++;
        } 
        else if (count == 4) {
            int bigus = (c & LAST_DATA_MASK);
            printf("\nbigus is %x\n", bigus);
            result = result | (c & LAST_DATA_MASK) << ((DATA_SIZE * counter2) + 4);
        }

        printf("\nthe result is %x \n", result);
        count++;
        printf("count %d \n", count-1);
        printf("----------------------------------------------\n");
    }  while(1);

    printf("after while, checkpoint 2\n");

   /* while( scanf( "%x", &v ) != EOF ){
        last = ( (v >> (DATA_SIZE +1) ) & 0x1 );
        int counter = 0;
        while ( !last ){
            result |= ( (v & DATA_MASK) << (DATA_SIZE * counter) );
            counter ++;
        }
        result <<= DATA_SIZE * counter;
        result |= signExtend();
        printf("%x", v);
    }*/
    
    fclose(f);
    return 0;
}