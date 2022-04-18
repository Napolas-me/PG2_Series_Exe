#include <stdio.h>
#include <limits.h>
//#include "func.h"

#define DATA_SIZE (CHAR_BIT - 1)
#define FINAL_MASK (1 << DATA_SIZE)
#define DATA_MASK 0x7F//(~(~0 << DATA_SIZE))
#define SIGN_SIZE 1
#define LAST_DATA_MASK 0xF

int signExtend(int value, int size){// size is n x 7, multiple of 7, size is the number of bits to store
    
    int mask1 = (-1 << size ); //place zeros in the location of value to store with size size, rest of the bits are ones
    int mask2 = ( ~ mask1 );   //place ones in the location of value to store with size size, rest of the bits are zeros
    
    
     
    int testBitSig = (value >> (size - 1)) & 0x1; 

    if(testBitSig)
        return (mask1 | value);
    else
        return (mask2 & value);
}


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

    //printf("before while, checkpoint 1\n");

    int v;
    int last;
    unsigned int result = 0;
    int counter2 = 0;
    printf("\nresult in dec:\n");
    do
    {
        // Taking input single character at a time
         int c = fgetc(f);
 
        // Checking for end of file
        if (feof(f))
            break ;

        //printf("%d-> char: %c dec: %d hex: %x\n", counter2, c, c, c);
        

        last = ( (c >> (DATA_SIZE) & 0x1 ) );
        //printf("the last is %x \n", last);
        
        if (!last ){
            int chungus = ( (c & DATA_MASK) << (DATA_SIZE * counter2) );
            //printf("\nchungus is %x\n", chungus);
            result = result | chungus;
            counter2 ++;
        } 
        else if (counter2 == 4) {
            int bigus = (c & LAST_DATA_MASK) << ((DATA_SIZE * (counter2 - 1)) + 7);
            //printf("\nbigus is %x\n", bigus);
            result = result | bigus ; //(c & LAST_DATA_MASK) << ((DATA_SIZE * counter2) + 4);
            counter2 = 0;
            //printf("\nthe result is %08x \nresult in dec: %d \n", result, result);
            printf("%d \n", result);
            result = 0;
        }
        else {
                 //printf("counter2 %d \n", counter2);
            int bigus = ( (c & DATA_MASK) << (DATA_SIZE * counter2) );
            //printf("\nbigus smaller is %x\n", bigus);
            result = result | bigus;
            result = signExtend( result , (DATA_SIZE * (counter2 + 1) ) );
            counter2 = 0;
            printf("%d \n", result);
            result = 0;
        }

        //printf("counter2 %d \n", counter2);
        //printf("----------------------------------------------\n");
    }  while(1);

    //printf("after while, checkpoint 2\n");
    
    fclose(f);
    return 0;
}