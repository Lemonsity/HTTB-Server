#include <stdint.h>

#define OPTIONS_C 1
#define GET_C 2
#define HEAD_C 3
#define POST_C 4
#define PUT_C 5
#define DELETE_C 6
#define TRACE_C 7
#define CONNECT_C 8 

#define OPTIONS "OPTIONS"
#define GET "GET"
#define HEAD "HEAD"
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"
#define TRACE "TRACE"
#define CONNECT "CONNECT"

int get_method(uint8_t * payload, int len);
