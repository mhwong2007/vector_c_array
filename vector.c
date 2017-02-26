/*
 * A vector implementation using C array
 */

#include <stdio.h>
#include <stdlib.h>

// vector struct
typedef struct Vector {
    // the array pointer
    int* arr;
    // the size of allocated array
    int size;
    // the occupied size of the array
    int count;

} Vector;

// vector initialiser
void initialise(struct Vector* vec) {
    vec->arr = NULL;
    vec->size = 0;
    vec->count = 0;

}

// push back function
void push_back(struct Vector* vec, int val) {
    // check the size
    if(vec-> size == 0) {
        vec->size = 10;
        vec->arr = malloc(vec->size*sizeof(int));
    }
    // check count
    if(vec->count == vec->size) {
        vec->size *= 2;
        vec->arr = realloc(vec->arr, vec->size*sizeof(int));
    }
    vec->arr[vec->count] = val;
    vec->count++;
}

// pop back function
void pop_back(struct Vector* vec) {
    // check occupied count
    if(vec->count == 0) {
        return;
    }
    vec->count--;
}

// the print function
void print(struct Vector* vec) {
    int i;
    printf("[ ");
    for(i = 0; i < vec->count; i++){
        printf("%d ", vec->arr[i]);
    }
    printf("]\n");
}

// get the front item
int get_front(struct Vector* vec) {
    if(vec->count == 0) {
        return -1;
    }
    return vec->arr[0];
}

// get the last item
int get_back(struct Vector* vec) {
    if(vec->count == 0) {
        return -1;
    }
    return vec->arr[vec->count-1];
}

// indexing
int get(struct Vector* vec, int i) {
    if(i >= vec->count) {
        return -1;
    }
    return vec->arr[i];
}

// get max_size
int max_size(struct Vector* vec) {
    return vec->size;
}

// get the current size of vector
int size(struct Vector* vec) {
    return vec->count;
}

// resize vector
void resize(struct Vector* vec, int size) {
    if(size < vec->count) {
        return;
    }
    vec->arr = realloc(vec->arr, size*sizeof(int));
    vec->size = size;
}

// shrink to fit
void shrink_to_fit(struct Vector* vec) {
    if(vec->count == 0) {
        return;
    }
    vec->arr = realloc(vec->arr, vec->count*sizeof(int));
    vec->size = vec->count;
}

// insert value at position i
void insert(struct Vector* vec, int i, int val) {
    // check the size
    if(vec-> size == 0) {
        vec->size = 10;
        vec->arr = malloc(vec->size*sizeof(int));
    }
    if(i > vec->count) {
        return;
    }
    // check count
    if(vec->count == vec->size) {
        vec->size *= 2;
        vec->arr = realloc(vec->arr, vec->size*sizeof(int));
    }
    if(vec->count == 0 && i == 0) {
        vec->count++;
        vec->arr[i] = val;
    }
    else {
        int j;
        for(j = vec->count -1;  j <= i; j--) {
            vec->arr[j+1] = vec->arr[j];
        }
        vec->arr[i] = val;
        vec->count++;
    }
}

// erase value at position i
void erase(struct Vector* vec, int i) {
    if(i > vec->count) {
        return;
    }
    if(i == 0 && vec->count == 1) {
        vec->count --;
    }
    else {
        int j;
        for(j = i; j+1 < vec->count; j++) {
            vec->arr[j] = vec->arr[j+1];
        }
        vec->count--;
    }
}

int main() {
    // declare a vector
    Vector vec;

    // initialise a vector
    initialise(&vec);
    printf("insert 99 at index 0\n");
    insert(&vec, 0, 99);
    print(&vec);
    int m_size = max_size(&vec);
    int sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    printf("erase val at index 0\n");
    erase(&vec, 0);
    print(&vec);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    int i;
    for(i = 0; i < 20; i++) {
        printf("push %d\n", i);
        push_back(&vec, i);
        print(&vec);
    }
    for(i = 0; i < 10; i++) {
        printf("pop\n");
        pop_back(&vec);
        print(&vec);
    }
    for(i = 0; i < 5; i++) {
        printf("push %d\n", (i+1)*2);
        push_back(&vec, (i+1)*2);
        print(&vec);
    }
    m_size = max_size(&vec);
    sz = size(&vec);
    int front = get_front(&vec);
    int back = get_back(&vec);
    int get_3 = get(&vec, 3);
    int get_exceed = get(&vec, sz);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    printf("front: %d\n", front);
    printf("back: %d\n", back);
    printf("get value at index 3: %d\n", get_3);
    printf("get value at index %d: %d\n", sz, get_exceed);
    printf("resize to 50\n");
    resize(&vec, 50);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    printf("resize to 1\n");
    resize(&vec, 1);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    printf("shrink to fit\n");
    shrink_to_fit(&vec);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    print(&vec);
    printf("insert 99 at index 10\n");
    insert(&vec, 10, 99);
    print(&vec);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    printf("insert 99 at index 100\n");
    insert(&vec, 100, 99);
    print(&vec);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);
    printf("erase val at index 9\n");
    erase(&vec, 9);
    print(&vec);
    m_size = max_size(&vec);
    sz = size(&vec);
    printf("max size: %d\n", m_size);
    printf("vector size: %d\n" ,sz);


    return 0;
}