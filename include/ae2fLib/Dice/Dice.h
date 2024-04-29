#pragma once

#ifndef AE2F_CPP_PREFIX
#ifdef AE2F_CPP
#define AE2F_CPP_PREFIX extern "C"
#else
#define AE2F_CPP_PREFIX
#endif // AE2F_CPP
#endif // !AE2F_CPP_PREFIX
#include <stdint.h>

#ifndef AE2F_DICE_DICE
#define AE2F_DICE_DICE
#define AE2F

typedef struct ae2f_Dice {
    uint32_t mt[624];
    int32_t mti;
}* ptr_ae2f_Dice;

#endif // !AE2F_DICE_PLAIN

#ifndef AE2F_DICE_DICE_FUN
#define AE2F_DICE_DICE_FUN

/// <param name="a">: dice</param>
/// <param name="b">: seed</param>
AE2F_CPP_PREFIX AE2F 
struct ae2f_Dice* ae2f_Dice(
    struct ae2f_Dice* a,
    uint32_t b
);

/// <param name="a">: dice</param>
/// <param name="b">: seed array</param>
/// <param name="c">: seed array length</param>
AE2F_CPP_PREFIX AE2F 
struct ae2f_Dice* ae2f_Dice_(
    struct ae2f_Dice* a,
    uint32_t* b,
    int32_t c
);

/// <param name="a">: dice</param>
AE2F_CPP_PREFIX AE2F 
uint32_t ae2f_Dice_int32(
    struct ae2f_Dice* a
);

/// <param name="a">: dice</param>
AE2F_CPP_PREFIX AE2F 
int32_t ae2f_Dice_int31(
    struct ae2f_Dice* a
);

/// <param name="a">: dice</param>
AE2F_CPP_PREFIX AE2F 
double ae2f_Dice_real(
    struct ae2f_Dice* a
);

/// <param name="a">: dice</param>
AE2F_CPP_PREFIX AE2F 
double ae2f_Dice_real_(
    struct ae2f_Dice* a
);

/// <param name="a">: dice</param>
AE2F_CPP_PREFIX AE2F 
double ae2f_Dice_real_2(
    struct ae2f_Dice* a
);

/// <param name="a">: dice</param>
AE2F_CPP_PREFIX AE2F 
double ae2f_Dice_res53(
    struct ae2f_Dice* a
);
#endif // !AE2F_DICE_DICE_FUN

#ifdef AE2F_CPP
#ifndef AE2F_DICE_DICE_CPP
#define AE2F_DICE_DICE_CPP

namespace ae2f {
    template<typename t>
    class fun;

#ifndef AE2F_DEF_CPP
#define AE2F_DEF_CPP
    template<typename t>
    class def {
    public:
        typedef t orig;
        typedef t* ptr;
    };
#endif

    namespace Dice {
        class Dice;
    }

    template<>
    class fun<Dice::Dice> {
    public:
        class getter;
        class starter;
    };

    class fun<Dice::Dice>::getter : public def<struct ae2f_Dice> {
    private:
        ptr p;
    public:

        inline getter(ptr a)
            : p(a) {}

        inline ptr raw() { return this->p; }

        inline uint32_t uint32() { return ae2f_Dice_int32(this->p); }
        inline uint32_t int32() { return ae2f_Dice_int31(this->p); }
        inline double real0() { return ae2f_Dice_real(this->p); }
        inline double real1() { return ae2f_Dice_real_(this->p); }
        inline double real2() { return ae2f_Dice_real_2(this->p); }
        inline double res53() { return ae2f_Dice_res53(this->p); }
    };
    class fun<Dice::Dice>::starter : 
        private getter, 
        public def<struct ae2f_Dice> 
    {
    public:
        inline starter(ptr p)
            : getter(p) {}

        /// <param name="a">: seed</param>
        inline getter ignite(uint32_t a) {
            ae2f_Dice(this->raw(), a);
            return this->raw();
        }

        /// <param name="a">: arr seed</param>
        /// <param name="b">: len seed</param>
        inline getter ignite(uint32_t* a, uint32_t b) {
            ae2f_Dice_(this->raw(), a, b);
            return this->raw();
        }
    };

    namespace Dice {
        class Dice : 
            public fun<Dice>::getter 
        {
        private:
            orig obj;
        public:
            /// <param name="a">: seed</param>
            inline Dice(uint32_t a)
                : getter(fun<Dice>::starter(&this->obj).ignite(a)) {}

            /// <param name="a">: arr seed</param>
            /// <param name="b">: len seed</param>
            inline Dice(uint32_t* a, uint32_t b)
                : getter(fun<Dice>::starter(&this->obj).ignite(a, b)) {}
        };
    }
}

#endif // !AE2F_DICE_DICE_CPP
#endif // AE2F_CPP