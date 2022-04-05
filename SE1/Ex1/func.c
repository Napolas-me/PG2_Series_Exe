#include "func.h"

int signExtend(int value, int size){
    int result = 0;

    while(size > 0){
        result &= (value & 0x1);
        result <<= 1;
        value >>= 1;
        size--;
    }

    return result;
}
