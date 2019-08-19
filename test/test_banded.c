#include "fasttransforms.h"
#include "ftutilities.h"

void test_bandedf(int * checksum);
void test_banded (int * checksum);
void test_bandedl(int * checksum);
void test_bandedq(int * checksum);

int main(void) {
    int checksum = 0;
    printf("\nTesting methods for banded matrices.\n");
    printf("\n\tSingle precision.\n\n");
    test_bandedf(&checksum);
    printf("\n\tDouble precision.\n\n");
    test_banded(&checksum);
    printf("\n\tLong double precision.\n\n");
    test_bandedl(&checksum);
    printf("\n\tQuadruple precision.\n\n");
    test_bandedq(&checksum);
    printf("\n");
    return checksum;
}

#define FLT float
#define X(name) FT_CONCAT(ft_, name, f)
#define Y(name) FT_CONCAT(, name, f)
#include "test_banded_source.c"
#undef FLT
#undef X
#undef Y

#define FLT double
#define X(name) FT_CONCAT(ft_, name, )
#define Y(name) FT_CONCAT(, name, )
#include "test_banded_source.c"
#undef FLT
#undef X
#undef Y

#define FLT long double
#define X(name) FT_CONCAT(ft_, name, l)
#define Y(name) FT_CONCAT(, name, l)
#include "test_banded_source.c"
#undef FLT
#undef X
#undef Y

#define FLT quadruple
#define X(name) FT_CONCAT(ft_, name, q)
#define Y(name) FT_CONCAT(, name, q)
#include "test_banded_source.c"
#undef FLT
#undef X
#undef Y
