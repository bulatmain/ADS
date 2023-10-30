#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void print_vector(const vector* v) {
    for (uint64_t i = 0; i < v->size; ++i) {
        printf("%ld\n", vat(*v, i));
    }
    printf("\n");
}


int main (int arc, int** argv) {

    vector v;

    int64_t* arr = (int64_t*)malloc(5 * sizeof(int64_t));
    for (int i = 0; i < 5; ++i) {
        arr[i] = i + 1;
    }

    init_vector(&v, 5, arr);

    print_vector(&v);

    resize_vector(&v, v.size + 1);

    push_vector(&v, 10);

    print_vector(&v);


    return 0;
}