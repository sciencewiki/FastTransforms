#include "fasttransforms.h"
#include "ftutilities.h"

#define FLT float
#define X(name) FT_CONCAT(ft_, name, f)
#define Y(name) FT_CONCAT(, name, f)
#include "test_hierarchical_source.c"
#undef FLT
#undef X
#undef Y

#define FLT double
#define X(name) FT_CONCAT(ft_, name, )
#define Y(name) FT_CONCAT(, name, )
#include "test_hierarchical_source.c"
#undef FLT
#undef X
#undef Y

#define FLT long double
#define X(name) FT_CONCAT(ft_, name, l)
#define Y(name) FT_CONCAT(, name, l)
#include "test_hierarchical_source.c"
#undef FLT
#undef X
#undef Y

#define FLT quadruple
#define X(name) FT_CONCAT(ft_, name, q)
#define Y(name) FT_CONCAT(, name, q)
#include "test_hierarchical_source.c"
#undef FLT
#undef X
#undef Y

int main(void) {
    int checksum = 0;
    printf("\nTesting methods for hierarchical matrices.\n");
    printf("\n\tSingle precision.\n\n");
    test_hierarchicalf(&checksum);
    printf("\n\tDouble precision.\n\n");
    test_hierarchical(&checksum);
    printf("\n\tLong double precision.\n\n");
    test_hierarchicall(&checksum);
    printf("\n\tQuadruple precision.\n\n");
    test_hierarchicalq(&checksum);
    printf("\n");
    return checksum;
}
