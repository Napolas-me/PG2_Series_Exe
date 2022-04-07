#include <stdio.h>
#include <limits.h>

#define DATA_SIZE (CHAR_BIT - 1)
#define FINAL_MASK (1 << DATA_SIZE)
#define DATA_MASK (~(~0 << DATA_SIZE)) // ~FINAL_MASK
#define SIGN_SIZE 1

int signExtend(int value, int size){// size is n x 7, multiple of 7, size is the number of bits to store
    
    int mask1 = (-1 << size ); //place zeros in the location of value to store with size size
    //int mask2 = ( -1 >> (sizeof(int) - size) );
    int mask2= ~mask1;
    int testBitSig = (value >> (size - 1)) & 0x1; 

    /*for(int i = 0; i <= size - 1; i++) {
        mask2 = mask2 | 0x1;
        mask2 = mask2 << 1;
    }
    mask2 = mask2 | 0x1;*/
     
    if(testBitSig)
        return (mask1 | value);
    else
        return (mask2 & value);
}


int main( int argc, char *argv[] ){

        printf("\n --- vaue of CHAR_BIT %d ", CHAR_BIT);
        printf("\n --- vaue of DATA_SIZE %d", DATA_SIZE);
        printf("\n --- vaue of FINAL_MASK %x ", FINAL_MASK);
        printf("\n --- vaue of DATA_MASK %x ", DATA_MASK);
        printf("\n --- vaue of DATA_MASK %x \n", DATA_MASK);


        int size = 5;
        int value = 0b01111;

        int mask1 = (-1 << size );
        int mask2 = ~mask1;

        /*for(int i = 0; i < size-1; i++) {
            mask2 = mask2 | 0x1;
            mask2 = mask2 << 1;
        } 
        mask2 = mask2 | 0x1;*/

        printf("\n --- mask1 is %x \n", mask1);
        printf("\n --- mask2 is %x \n", mask2);

        int result = signExtend(value, size);
        printf("\n --- Result in hex is %x \n", result);
        printf("\n --- Result in dec is %d \n", result);



    return 0;
}