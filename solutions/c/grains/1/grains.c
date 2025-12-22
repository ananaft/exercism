#include "grains.h"

#define ARR_LEN 64

uint64_t square(uint8_t index) {
    uint64_t arr[ARR_LEN];
    uint64_t value = 1;
    
    for (uint8_t i = 0; i < ARR_LEN; i++) {
        arr[i] = value;
        value *= 2;
    }
    
    if (index < 1 || index > ARR_LEN) {
        return 0;
    }
    
    return arr[index-1];
}

uint64_t total(void) {
    uint64_t arr[ARR_LEN];
    uint64_t value = 1;
    uint64_t sum;

    for (uint8_t i = 0; i < ARR_LEN; i++) {
        arr[i] = value;
        value *= 2;
    }
    
    for (uint8_t i = 0; i < ARR_LEN; i++) {
        sum += arr[i];
    }
    return sum;
}