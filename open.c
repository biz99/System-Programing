#include "kvs.h"
#include <stdlib.h>
#include <string.h>

node_t* createNode(int level, const char* key, const char* value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if (!node) return NULL;

    strcpy(node->key, key);
    node->value = value ? strdup(value) : NULL;
    node->level = level;
    for (int i = 0; i < MAX_LEVEL; i++) {
        node->forward[i] = NULL;
    }
    return node;
}

kvs_t* open() {
    kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
    if (!kvs) return NULL;

    kvs->level = 1;
    kvs->items = 0;
    kvs->header = createNode(MAX_LEVEL, "", NULL); // Header node with maximum level

    return kvs;
}

