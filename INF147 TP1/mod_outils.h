#ifndef __MOD_OUTILS__
#define __MOD_OUTILS__

#define SWAP(X, Y)		*X = *X ^ *Y;\
						*Y = *X ^ *Y;\
						*X = *X ^ *Y;

#endif