#include "func.h"

int signExtend(int value, int size){// size is n x 7, multiple of 7, size is the number of bits to store
    int result = 0;
    int mask = (-1 >> (sizeof(int) - size) );
    int testSig = (value >> (size + 1)) & 0x1;
    
    if(testSig)
        result = -1 | (mask & value);
    else
        result = mask & value

    while(size > 0){ // not right
        result &= (value & 0x1);
        result <<= 1;
        value >>= 1;
        size--;
    }

    return result;
}
