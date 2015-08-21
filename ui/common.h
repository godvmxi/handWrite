#ifndef COMMON_H
#define COMMON_H

enum {
    CMD_INVALID = -1,
    CMD_ERROR =  0,
    CMD_QUERY_MODULES = 1,
    CMD_ACK_MODULES  = 2 ,
    CMD_QUERY_CUR_MODULE  = 3,
    CMD_ACM_CUR_MODULE = 4,
    CMD_QUERY_STROKES = 5,
    CMD_ACK_STROKES = 6
}Cmd;
#endif // COMMON_H
