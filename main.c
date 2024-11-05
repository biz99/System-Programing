#include "kvs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    kvs_t* kvs = open();
    if (!kvs) {
        printf("Failed to open kvs\n");
        return -1;
    }

    FILE* query_file = fopen("query.dat", "r");
    FILE* answer_file = fopen("answer.dat", "w");
    if (!query_file || !answer_file) {
        printf("Failed to open input/output files\n");
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), query_file)) {
        char command[10], key[100], value[100];
        int scanned = sscanf(line, "%[^,],%[^,],%s", command, key, value);

        if (strcmp(command, "set") == 0 && scanned == 3) {
            put(kvs, key, value);
        } else if (strcmp(command, "get") == 0 && scanned >= 2) {
            char* result = get(kvs, key);
            if (result) {
                fprintf(answer_file, "%s\n", result);
            } else {
                fprintf(answer_file, "-1\n");
            }
        }
    }

    fclose(query_file);
    fclose(answer_file);
    close(kvs);
    return 0;
}

