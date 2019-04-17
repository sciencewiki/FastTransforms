// Utility functions for testing.

#include "ftutilities.h"

#define A(i,j) A[(i)+n*(j)]
#define B(i,j) B[(i)+n*(j)]

void printmat(char * MAT, char * FMT, double * A, int n, int m) {
    printf("%s = \n", MAT);
    if (n > 0 && m > 0) {
        if (signbit(A(0,0))) {printf("[");}
        else {printf("[ ");}
        printf(FMT, A(0,0));
        for (int j = 1; j < m; j++) {
            if (signbit(A(0,j))) {printf("  ");}
            else {printf("   ");}
            printf(FMT, A(0,j));
        }
        for (int i = 1; i < n-1; i++) {
            printf("\n");
            if (signbit(A(i,0))) {printf(" ");}
            else {printf("  ");}
            printf(FMT, A(i,0));
            for (int j = 1; j < m; j++) {
                if (signbit(A(i,j))) {printf("  ");}
                else {printf("   ");}
                printf(FMT, A(i,j));
            }
        }
        if (n > 1) {
            printf("\n");
            if (signbit(A(n-1,0))) {printf(" ");}
            else {printf("  ");}
            printf(FMT, A(n-1,0));
            for (int j = 1; j < m; j++) {
                if (signbit(A(n-1,j))) {printf("  ");}
                else {printf("   ");}
                printf(FMT, A(n-1,j));
            }
        }
        printf("]\n");
    }
}

double * copymat(double * A, int n, int m) {
    double * B = (double *) calloc(n*m, sizeof(double));
    for (int i = 0; i < n*m; i++)
        B[i] = A[i];
    return B;
}

double * sphones(int n, int m) {
    double * A  = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 1.0;
    return A;
}

double * sphrand(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * triones(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-i; j++)
            A(i,j) = 1.0;
    return A;
}

double * trirand(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * diskones(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-4*i; j++)
            A(i,j) = 1.0;
    return A;
}

double * diskrand(int n, int m) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m-4*i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * tetones(int n, int l, int m) {
    double * A = (double *) calloc(n * l * m, sizeof(double));
    for (int k = 0; k < m; k++)
        for (int j = 0; j < l-k; j++)
            for (int i = 0; i < n-j-k; i++)
                A[i+l*(j+n*k)] = 1.0;
    return A;
}

double * tetrand(int n, int l, int m) {
    double * A = (double *) calloc(n * l * m, sizeof(double));
    for (int k = 0; k < m; k++)
        for (int j = 0; j < l-k; j++)
            for (int i = 0; i < n-j-k; i++)
                A[i+l*(j+n*k)] = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double * spinsphones(int n, int m, int s) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n-s; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 1.0;
    return A;
}

double * spinsphrand(int n, int m, int s) {
    double * A = (double *) calloc(n * m, sizeof(double));
    for (int i = 0; i < n-s; i++)
        for (int j = 0; j < m-2*i; j++)
            A(i,j) = 2.0*(((double) rand())/RAND_MAX)-1.0;
    return A;
}

double elapsed(struct timeval * start, struct timeval * end, int N) {
    return ((end->tv_sec  - start->tv_sec) * 1000000u + end->tv_usec - start->tv_usec) / (1.e6 * N);
}

#define FLT float
#define X(name) CONCAT(, name, f)
#include "ftutilities_source.c"
#undef FLT
#undef X

#define FLT double
#define X(name) CONCAT(, name, )
#include "ftutilities_source.c"
#undef FLT
#undef X

#define FLT long double
#define X(name) CONCAT(, name, l)
#include "ftutilities_source.c"
#undef FLT
#undef X

#define FLT quadruple
#define X(name) CONCAT(, name, q)
#include "ftutilities_source.c"
#undef FLT
#undef X
