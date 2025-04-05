#include "../include/binpow.h"

int binpow(int digit, int power, int mod) {
    int res = 1;
    while (power > 0) {
        if( power % 2 == 1) res = (res * digit) % mod;
        digit = (digit * digit) % mod;
        power = power / 2;
    }
    return res;
}