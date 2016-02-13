/* Provides aliases for some types and C keywords I don't like.
   From https://github.com/AnotherKamila/chaOS/ (cslibc/inc/Csucks.h). */

#ifndef CSUCKS_H
#define CSUCKS_H


// everybody wants these anyway
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define intern    static // for use in file scope
#define common    static // for use in function scope
#define readonly  const  // it's not constant, it's just read-only!

#define byte  char // to be used with signed/unsigned (that's why it isn't a typedef)

static inline int min(const int a, const int b) { return (a < b) ? a : b; }
static inline int max(const int a, const int b) { return (a < b) ? b : a; }


#endif
