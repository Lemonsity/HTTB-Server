#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "method.h"

int get_method(uint8_t * payload /*borrow*/, int len) {
    bool found = false;
    int i = 0;
    for (; i < len; i++) {
        if (payload[i] == ' ') {
            found = true;
            break;
        }
    }
    if (!found) {
        return -1;
    }

    //TODO the indexing is a bit weird atm

    uint8_t method_name[i + 2];
    memcpy(method_name, payload, i + 1);
    method_name[i + 1] = '\0';
    if (strcmp(method_name, OPTIONS)) {
        return OPTIONS_C;
    }
    if (strcmp(method_name, GET)) {
        return GET_C;
    }
    if (strcmp(method_name, HEAD)) {
        return HEAD_C;
    }
    if (strcmp(method_name, POST)) {
        return POST_C;
    }
    if (strcmp(method_name, PUT)) {
        return PUT_C;
    }
    if (strcmp(method_name, DELETE)) {
        return DELETE_C;
    }
    if (strcmp(method_name, TRACE)) {
        return TRACE_C;
    }
    if (strcmp(method_name, CONNECT)) {
        return CONNECT_C;
    }
    return -1;
}
