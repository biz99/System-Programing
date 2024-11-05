#include "kvs.h"
#include <stdlib.h>
#include <string.h>

char* get(kvs_t* kvs, const char* key) {
    node_t* x = kvs->header;

    for (int i = kvs->level - 1; i >= 0; i--) {
        while (x->forward[i] != NULL && strcmp(x->forward[i]->key, key) < 0) {
            x = x->forward[i];
        }
    }
    x = x->forward[0];

    if (x != NULL && strcmp(x->key, key) == 0) {
        return x->value;
    } else {
        return NULL;
    }
}

