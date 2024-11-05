#include "kvs.h"

int close(kvs_t* kvs) {
    if (!kvs) return 0;
    
    node_t* node = kvs->header->forward[0];
    while (node != NULL) {
        node_t* next = node->forward[0];
        // free(node->key);  // 제거: key가 배열이라면 해제할 필요가 없습니다.
        free(node->value);   // 동적으로 할당된 값만 해제
        // free(node->forward);  // 제거: forward가 배열이라면 해제할 필요가 없습니다.
        free(node);
        node = next;
    }
    // free(kvs->header->forward);  // 제거: forward가 배열이라면 해제할 필요가 없습니다.
    free(kvs->header);
    free(kvs);
    return 0;
}

