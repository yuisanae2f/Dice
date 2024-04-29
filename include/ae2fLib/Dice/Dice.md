# Dice
> generates the random number by [`Mersenne Twister`](https://en.wikipedia.org/wiki/Mersenne_Twister#Pseudocode).

Code
```c
struct ae2f_Dice {
    unsigned long mt[624];
    int mti;
};
```

# init
## ae2f_Dice
> initialises the given structure `_this` with a `seed`.

Code
```c
struct ae2f_Dice* ae2f_Dice(
    struct ae2f_Dice* _this,
    uint32_t seed
);
```

## ae2f_Dice_
> initialises the given structure `_this` with a array of `seed` as a length of `len`.

Code
```c
struct ae2f_Dice* ae2f_Dice_(
    struct ae2f_Dice* _this,
    uint32_t* seed,
    int32_t len
);
```

# gen
## ae2f_Dice_int32
> generates the random number of `unsigned long` from `_this`.

Code
```c
uint32_t ae2f_Dice_int32(
    struct ae2f_Dice* _this
);
```

## ae2f_Dice_int31
> generates the random number of `long` from `_this`.

Code
```c
int32_t ae2f_Dice_int31(
    struct ae2f_Dice* _this
);
```


## ae2f_Dice_real
> generates the random number of `double` from `_this`.

Code
```c
double ae2f_Dice_real(
    struct ae2f_Dice* _this
);
```

## ae2f_Dice_real_
> generates the random number of `double` from `_this`.

Code
```c
double ae2f_Dice_real_(
    struct ae2f_Dice* _this
);
```

## ae2f_Dice_real_2
> generates the random number of `double` from `_this`.

Code
```c
double ae2f_Dice_real_2(
    struct ae2f_Dice* _this
);
```

## ae2f_Dice_res53
> generates the random number of `double` from `_this`.

Code
```c
double ae2f_Dice_res53(
    struct ae2f_Dice* _this
);
```

# Abstraction
## getter
Code
```cpp
getter(ptr a);
```

### raw
> is the getter for an primitive pointer type.

### uint32
Code
```cpp
uint32_t uint32();
```

Ref
- [ae2f_Dice_int32](#ae2f_dice_int32)

### int32
- [ae2f_Dice_int31](#ae2f_dice_int31)
### real0
- [ae2f_Dice_real](#ae2f_dice_real)
### real1
- [ae2f_Dice_real_](#ae2f_dice_real_)
### real2
- [ae2f_Dice_real_2](#ae2f_dice_real_2)
### res53
- [ae2f_Dice_res53](#ae2f_dice_res53)
## starter
### ignite
Code
```cpp
getter ignite(
    uint32_t seed
);
```

Ref
- [ae2f_Dice](#ae2f_dice)

Code
```cpp
getter ignite(
    uint32_t* seed,
    uint32_t len
);
```

Ref
- [ae2f_Dice_](#ae2f_dice_)

# Classes
## Dice : [getter](#getter)