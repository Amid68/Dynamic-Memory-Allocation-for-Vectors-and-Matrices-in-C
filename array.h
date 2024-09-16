#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "xmalloc.h"

// macro to create a vector
#define make_vector(v, n) ((v) = xmalloc((n) * sizeof *(v)))

// macro to free a vector
#define free_vector(v) do { free(v); v = NULL; } while (0)

// macro to create a matrix
#define make_matrix(a, m, n) do { \
    size_t make_matrix_loop_counter; \
    make_vector(a, (m) + 1); \
    for (make_matrix_loop_counter = 0; \
         make_matrix_loop_counter < (m); \
         make_matrix_loop_counter++) \
        make_vector((a)[make_matrix_loop_counter], (n)); \
    (a)[m] = NULL; \
} while (0)

// macro to free a matrix
#define free_matrix(a) do { \
    if (a != NULL) { \
        size_t make_matrix_loop_counter; \
        for (make_matrix_loop_counter = 0; \
             (a)[make_matrix_loop_counter] != NULL; \
             make_matrix_loop_counter++) \
            free_vector((a)[make_matrix_loop_counter]); \
        free_vector(a); \
        a = NULL; \
    } \
} while (0)

#endif
