#include "bullshit.h"
#include "ae2fLib/Dice/Dice.h"

/* Period parameters */
#define AE2F_DICE_N 624
#define AE2F_DICE_M 397
#define AE2F_DICE_MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define AE2F_DICE_UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define AE2F_DICE_LOWER_MASK 0x7fffffffUL /* least significant r bits */

AE2F struct ae2f_Dice* ae2f_Dice(struct ae2f_Dice* _this, uint32_t seed)
{
    _this->mt[0] = seed & 0xffffffffUL;

    AE2F_FOR(, _this->mti = 1, _this->mti < AE2F_DICE_N, _this->mti++, 
        _this->mt[_this->mti] =
        (1812433253UL * (_this->mt[_this->mti - 1] ^ (_this->mt[_this->mti - 1] >> 30)) + _this->mti);
    _this->mt[_this->mti] &= 0xffffffffUL;
    );

    return _this;
}

AE2F struct ae2f_Dice* ae2f_Dice_(struct ae2f_Dice* _this, uint32_t* seed, int32_t len)
{
    int i, j, k;
    ae2f_Dice(_this, 19650218UL);
    i = 1; j = 0;
    k = (AE2F_DICE_N > len ? AE2F_DICE_N : len);

#pragma region for
    AE2F_FOR(, k, k--,
        _this->mt[i] = (_this->mt[i] ^ ((_this->mt[i - 1] ^ (_this->mt[i - 1] >> 30)) * 1664525UL))
        + seed[j] + j;
    _this->mt[i] &= 0xffffffffUL;
    i++; j++;

    switch (i)
    {
    case AE2F_DICE_N:
        _this->mt[0] = _this->mt[AE2F_DICE_N - 1]; i = 1;
    default:
        switch (j >= len)
        {
        case 1: j = 0;
        default: break;
        } break;
    }
    );
#pragma endregion
#pragma region for
    AE2F_FOR(_, k = AE2F_DICE_N - 1, k, k--,
        _this->mt[i] = (_this->mt[i] ^ ((_this->mt[i - 1] ^ (_this->mt[i - 1] >> 30)) * 1566083941UL))
        - i;
    _this->mt[i] &= 0xffffffffUL;
    i++;

    switch (i)
    {
    case AE2F_DICE_N: _this->mt[0] = _this->mt[AE2F_DICE_N - 1]; i = 1;
    default: break;
    }
    );
#pragma endregion

    _this->mt[0] = 0x80000000UL;
    return _this;
}

AE2F unsigned long ae2f_Dice_int32(struct ae2f_Dice* _this)
{
    unsigned long y;
    static unsigned long mag01[2] = { 0x0UL, AE2F_DICE_MATRIX_A };

    switch (_this->mti)
    {
    case AE2F_DICE_N + 1:
        ae2f_Dice(_this, 5489UL);

    case AE2F_DICE_N:;
        int kk;
#pragma region for
        AE2F_FOR(a, kk = 0, kk < AE2F_DICE_N - AE2F_DICE_M, kk++,
            y = (_this->mt[kk] & AE2F_DICE_UPPER_MASK) | (_this->mt[kk + 1] & AE2F_DICE_LOWER_MASK);
        _this->mt[kk] = _this->mt[kk + AE2F_DICE_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
        );
#pragma endregion
#pragma region for
        AE2F_FOR(b,,kk < AE2F_DICE_N - 1, kk++,
            y = (_this->mt[kk] & AE2F_DICE_UPPER_MASK) | (_this->mt[kk + 1] & AE2F_DICE_LOWER_MASK);
        _this->mt[kk] = _this->mt[kk + (AE2F_DICE_M - AE2F_DICE_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        );
#pragma endregion
        y = (_this->mt[AE2F_DICE_N - 1] & AE2F_DICE_UPPER_MASK) | (_this->mt[0] & AE2F_DICE_LOWER_MASK);
        _this->mt[AE2F_DICE_N - 1] = _this->mt[AE2F_DICE_M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        _this->mti = 0;

    default:
        y = _this->mt[_this->mti++];

        y ^= (y >> 11);
        y ^= (y << 7) & 0x9d2c5680UL;
        y ^= (y << 15) & 0xefc60000UL;
        y ^= (y >> 18);

        return y;
    }
}

AE2F long ae2f_Dice_int31(struct ae2f_Dice* _this)
{
    return (long)(ae2f_Dice_int32(_this) >> 1);
}

AE2F double ae2f_Dice_real(struct ae2f_Dice* _this)
{
    return ae2f_Dice_int32(_this) * (1.0 / 4294967295.0);
}

AE2F double ae2f_Dice_real_(struct ae2f_Dice* _this)
{
    return ae2f_Dice_int32(_this) * (1.0 / 4294967296.0);
}


AE2F double ae2f_Dice_real_2(struct ae2f_Dice* _this)
{
    return (((double)ae2f_Dice_int32(_this)) + 0.5) * (1.0 / 4294967296.0);
    /* divided by 2^32 */
}

AE2F double ae2f_Dice_res53(struct ae2f_Dice* _this)
{
    unsigned long a = ae2f_Dice_int32(_this) >> 5, b = ae2f_Dice_int32(_this) >> 6;
    return(a * 67108864.0 + b) * (1.0 / 9007199254740992.0);
}