#include "func.h"

int signExtend(int value, int size){// size is n x 7, multiple of 7, size is the number of bits to store
    
    int mask1 = (-1 << size ); //place zeros in the location of value to store with size size, rest of the bits are ones
    int mask2 = ( ~ mask1 );   //place ones in the location of value to store with size size, rest of the bits are zeros
    
    
     
    int testBitSig = (value >> (size - 1)) & 0x1; 

    if(testBitSig)
        return (mask1 | value);
    else
        return (mask2 & value);
}
