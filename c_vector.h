#ifndef C_VECTOR_H
#define C_VECTOR_H

#include <stdlib.h>

typedef struct c_vector
{
    void *data;
    size_t size;
    size_t capacity;
} c_vector;

/*
    TODO:
        Add sort
*/

#define v_new(type, capacity) {(type *)malloc(sizeof(type) * capacity), 0, (capacity)}
#define v_init(type, vector, cap) { \
        vector.data = (type *)malloc(sizeof(type) * (cap)); \
        vector.size = 0; \
        vector.capacity = (cap); \
    }

#define v_push(type, vector, value) { \
    if (vector.size < vector.capacity) {\
        ((type *)vector.data)[vector.size] = value;\
        vector.size++;}\
    else {\
        vector.capacity *= 2;\
        vector.data = (type *)realloc(vector.data, sizeof(type) * vector.capacity);\
        ((type *)vector.data)[vector.size] = value;\
        vector.size++;} \
}

#define v_pop(vector) { \
    if (vector.size > 0)\
        vector.size--;\
}

#define v_insert(type, vector, idx, value) { \
    if (vector.size < vector.capacity) {\
        for (size_t i = vector.size; i > idx; i--) {\
            ((type *)vector.data)[i] = ((type *)vector.data)[i - 1];\
        }\
        ((type *)vector.data)[idx] = value;\
        vector.size++;\
    }\
    else {\
        vector.capacity *= 2;\
        vector.data = (type *)realloc(vector.data, sizeof(type) * vector.capacity);\
        for (size_t i = vector.size; i > idx; i--) {\
            ((type *)vector.data)[i] = ((type *)vector.data)[i - 1];\
        }\
        ((type *)vector.data)[idx] = value;\
        vector.size++;\
    }\
}

#define v_erase(vector, idx) { \
    if (vector.size > 0) {\
        for (size_t i = idx; i < vector.size - 1; i++) {\
            ((int *)vector.data)[i] = ((int *)vector.data)[i + 1];\
        }\
        vector.size--;\
    }\
}

#define v_free(vector) { \
    free(vector.data);\
    vector.data = NULL;\
    vector.size = 0;\
    vector.capacity = 0;\
}

#define v_get(type, vector, idx) ((type *)vector.data)[idx]

#define v_set(type, vector, idx, value) ((type *)vector.data)[idx] = value

#define v_begin(vector) ((int *)vector.data)

#define v_end(vector) ((int *)vector.data + vector.size)

#define v_clear(vector) vector.size = 0;

#define v_reserve(type, vector, capacity) { \
    if (capacity > vector.capacity) {\
        vector.capacity = capacity;\
        vector.data = (type *)realloc(vector.data, sizeof(type) * vector.capacity);\
    }\
}

#define v_shrink(type, vector) { \
    if (vector.capacity > 0) {\
        vector.capacity = vector.size;\
        vector.data = (type *)realloc(vector.data, sizeof(type) * vector.size);\
    }\
}

#define v_empty(vector) (vector.size == 0)

#define v_swap(type, vector, first, second) {\
    type tmp = v_get(type, vector, first); \
    v_set(type, vector, first, v_get(type, vector, second)); \
    v_set(type, vector, second, tmp); \
}\

#endif  //C_VECTOR_H