#include "vector.h"
#include <stddef.h>

vector create_vector(const uint64_t size, const int64_t* p) {
    vector v;
    v.size = size;
    if (size == 0) {
        v.p = NULL;
        return v;
    }
    v.p = (int64_t*)malloc(sizeof(int64_t) * v.size);
    for (uint64_t i = 0; i < v.size; ++i) {
        v.p[i] = p[i];
    }
    return v;
}

void init_vector(vector* v, const uint64_t size, const int64_t* p) {
    *v = create_vector(size, p);
}

void clear_vector(vector* v) {
    free(v->p);
    v->size = 0;
    v->p = NULL;
}

void copy_vector(vector* v, const vector* v_) {
    clear_vector(v);
    init_vector(v, v_->size, v_->p);
}

void resize_vector(vector* v, uint64_t size) {
    if (v->size == size) {
        return;
    }
    uint64_t mn = (v->size < size ? v->size : size);
    int64_t* p = (int64_t*)malloc(size * sizeof(int64_t));
    for (uint64_t i = 0; i < mn; ++i) {
        p[i] = vat(*v, i);
    }
    clear_vector(v);
    init_vector(v, size, p);
}

void push_vector(vector* v, const int64_t e) {
    resize_vector(v, v->size + 1);
    vat(*v, v->size - 1) = e;
}

uint64_t size_vector(const vector* v) {
    return v->size;
}

int8_t is_empty_vector(const vector* v) {
    return v->size == 0 && v->p == NULL;
}

int8_t equal_vectors(const vector* v, const vector* v_) {
    if (v->size != v_->size) {
        return 0;
    }
    for (uint64_t i = 0; i < v->size; ++i) {
        if (v->p[i] != v_->p[i])
            return 0;
    }
    return 1;
}
