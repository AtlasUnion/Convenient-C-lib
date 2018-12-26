//
// Created by ryan on 12/26/18.
//
#include "my_string.h"

/**
 * @brief str_concat concat variable number of strings
 * @param count - number of string to concat
 * @param ... - actual list of strings
 * @return concated string if success; NULL if failed
 */
char* str_concat(int count, ...) {
    va_list ap;
    size_t len = 0;

    if (count < 1) // if no input string
        return NULL;

    /*
     * get list of string's total length
     */
    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        const char* tmp_str = va_arg(ap, char*);
        len += strlen(tmp_str);
    }
    va_end(ap);

    char* ret = malloc(len + 1);
    memset(ret, '\0', len+1);
    if (ret == NULL)
        return NULL;

    /*
     * copy from src strings to dest string
     */
    char* dst = ret;
    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        const char *src = va_arg(ap, char*);

        while(*dst++ = *src++);
        dst--;
    }
    va_end(ap);
    return ret;
}
