#include <stdio.h>
#include <stdlib.h>

#ifndef FATAL_H
#define FATAL_H

#define Error(Str) FatalError(Str)
#define FatalError(Str) fprintf(stderr, "%s\n", Str), exit(1)

#endif // FATAL_H
