#include <stdio.h>
#include "flush.h"

void flush()
{
    fflush(stdin);
    fflush(stdout);
}