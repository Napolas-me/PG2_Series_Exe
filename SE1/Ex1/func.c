#include "func.h"

int signExtend(int value, int size){// size is n x 7, multiple of 7, size is the number of bits to store
    
    int mask1 = (-1 << size ); //place zeros in the location of value to store with size size
    //int mask2 = ( -1 >> (sizeof(int) - size) );
    int mask2 = 0;
    
    for(int i = 0; i <= size - 1; i++) {
        mask2 = mask2 | 0x1;
        mask2 = mask2 << 1;
    }
    mask2 = mask2 | 0x1;
     
    int testBitSig = (value >> (size - 1)) & 0x1; 

    if(testBitSig)
        return (mask1 | value);
    else
        return (mask2 & value);
}
