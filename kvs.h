#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 16

struct node {
    char key[100];
    char* value;
    struct node* forward[MAX_LEVEL];
    int level;
};

typedef struct node node_t;

struct kvs {
    struct node* header; // Skip list header node
    int level;           // Current level of the skip list
    int items;           // Number of items in the skip list
};

typedef struct kvs kvs_t;

kvs_t* open();
int close(kvs_t* kvs); // Free all memory space
int put(kvs_t* kvs, const char* key, const char* value); // Insert key-value pair
char* get(kvs_t* kvs, const char* key); // Retrieve value by key
node_t* createNode(int level, const char* key, const char* value);

