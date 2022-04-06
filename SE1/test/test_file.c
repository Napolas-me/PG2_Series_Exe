#include <stdio.h>
#include <limits.h>

#define DATA_SIZE (CHAR_BIT - 1)
#define FINAL_MASK (1 << DATA_SIZE)
#define DATA_MASK (~(~0 << DATA_SIZE)) // ~FINAL_MASK
#define SIGN_SIZE 1

int main( int argc, char *argv[] ){

        printf("\n --- vaue of CHAR_BIT %d ", CHAR_BIT);
        printf("\n --- vaue of DATA_SIZE %d", DATA_SIZE);
        printf("\n --- vaue of FINAL_MASK %x ", FINAL_MASK);
        printf("\n --- vaue of DATA_MASK %x ", DATA_MASK);
        printf("\n --- vaue of DATA_MASK %x ", DATA_MASK);

    return 0;
}