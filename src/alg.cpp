// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    for (int i = 2; i * i <= value; i++) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t counter = 0, number = 1;
    while (counter < n) {
        number++;
        if (checkPrime(number)) counter++;
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t number = value;
    do {
        number++;
    } while (!checkPrime(number));
    return number;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound < 3) return 0;
    uint64_t sum = 0, number = 2;
    while (number < hbound) {
        if (checkPrime(number)) sum+=number;
        number++;
    }
    return sum;
}
