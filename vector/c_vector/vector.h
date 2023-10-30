#ifndef VECTOR_H

#define VECTOR_H
#include <inttypes.h>
#include <stdlib.h>

// Vector is a data structure that represents a dynamic size array.

typedef struct
{
    int64_t* p;
    uint64_t size;
} vector;

// create a new vetor with given size and fill it with given set of arguments
vector create_vector(const uint64_t size, const int64_t* p);

void init_vector(vector* v, const uint64_t size, const int64_t* p);

// copy v_ to v
void copy_vector(vector* v, const vector* v_);

// Makes vector v empty
void clear_vector(vector* v);

// Resizes given vector
void resize_vector(vector* v, uint64_t size);

// Pushes element e to the end of vector. Resises if neccessary.
void push_vector(vector* v, const int64_t e);

// Gives an acces to vector element with index i 
#define vat(v, i) \
    (v).p[i]

// Returns size of given vector
uint64_t size_vector(const vector* v);

// Checks if given vector is empty
int8_t is_empty_vector(const vector* v);

// Checks is given vectors are equal
int8_t equal_vectors(const vector* v, const vector* v_);

#endif
