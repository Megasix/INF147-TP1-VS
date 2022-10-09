#ifndef __MOD_OUTILS__
#define __MOD_OUTILS__

#define SWAP(x, y) \
{                  \
*x = *x ^ *y;      \
*y = *x ^ *y;      \
*x = *x ^ *y;      \
};

#endif