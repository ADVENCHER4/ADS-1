// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    uint64_t divider;
    divider = value / 2;
    for (int i = divider; i > 1; i--) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    uint64_t counter = 0, number = 1;
    uint64_t divider;
    bool isPrime;
    while (counter < n) {
        isPrime = true;
        number++;
        divider = number / 2;
        for (int i = divider; i > 1; i--) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) counter++;
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t number = value;
    uint64_t divider;
    bool isPrime;
    do {
        isPrime = true;
        number++;
        divider = number / 2;
        for (int i = divider; i > 1; i--) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
    } while (!isPrime);
    return number;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound < 3) return 0;
    uint64_t sum = 2;
    for (uint64_t i = 3; i < hbound; i += 2) {
        if (checkPrime(i))  sum += i;
    }
    return sum;
}
