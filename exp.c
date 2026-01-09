#include <stdio.h>
#include <stdlib.h>

float exp(float x){
    const double inv_ln2 = 1.4426950408889634; // 1/ln(2)
    const double ln2 = 0.6931471805599453;

    // z = x / ln(2)
    float y = x * inv_ln2;

    // split z = k + r pour calcule 2^k et utilise polynome pour aproximation de 2^r
    int k = (int)y;
    float r = y - k;

    // polynomial approximation for 2^r
    float p = 1.0 + r * ln2 + 0.5 * (r * ln2) * (r * ln2);

    // build 2^k using exponent bits find 2^k with set k+127 in exponent place and set 0 in manitssa and bit of sign
    unsigned  bits = ((unsigned)(k + 127)) << 23;
    float two_k = *(float*)&bits;

	// return 2^k *2^r
    return two_k * p;
}
