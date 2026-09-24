#include "mem_stream.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stream_flags.h"

/* ignores IO_CREATE i.e buf must exist */
mem_file_t* mopen(void* buf, size_t size, const char* mode) {
    mem_file_t* p;
    int flags = stream_mode_to_flags(mode);
    if(flags < 0 || !buf || (char*)buf + size <= (char*)buf) {
        errno = EINVAL;
        return NULL;
    }
    p = malloc(sizeof(*p));
    if(!p) {
        errno = ENOMEM;
        return NULL;
    }
    p->flags = flags | IO_STRING;
    p->begin = buf;
    p->end = (char*)buf + size;
    if (flags & IO_TRUNCATE) {                          /* "w", "w+" and binary */
        p->etx = p->begin;
        p->pos = p->begin;
        if (!(flags & IO_BINARY)) p->begin[0] = '\0';   /* valid empty string */
    }
    else if (flags & IO_APPEND) {                       /* "a", "a+" and binary */
        if (flags & IO_BINARY) p->etx = p->end;         /* size marks end of data */
        else p->etx = memchr(p->begin, '\0', size);     /* scan for NUL terminator */
        p->etx = (p->etx) ?p->etx :p->end;              /* no NUL: buffer is full */
        p->pos = p->etx;                                /* append at etx */
    }
    else {                                              /* "r", "r+" and binary */
        p->etx = p->end;                                /* whole buffer is data */
        p->pos = p->begin;
    }
    return p;
}

int mclose(mem_file_t* mstream) {
    if(mstream) {
        free(mstream);
        return 0;
    }
    errno = EBADF;
    return EOF;
}
