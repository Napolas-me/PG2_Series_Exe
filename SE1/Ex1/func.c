#include "func.h"

int signExtend(int value, int size){// size is n x 7
    int result = 0;
    int testSig = (value >> size) & 0x1;
    
    if(testSIg) result = 0xFFFF;// set to max value int

    while(size > 0){ // not right
        result &= (value & 0x1);
        result <<= 1;
        value >>= 1;
        size--;
    }

    return result;
}
