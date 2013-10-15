#include <stdio.h>
#include "tools.h"

long Tools::getRSS()
{
    long s = -1;
    FILE *f = fopen("/proc/self/statm", "r");
    if (!f) return -1;
    fscanf(f, "%ld", &s);
    fclose (f);
    return s;
}
