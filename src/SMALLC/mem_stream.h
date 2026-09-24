/**
* @author       Jeremy Simon Thornton
* @copyright    2026 Jeremy Simon Thornton
*
* The Watcom C compiler and, ergo, the Open Watcom C compiler, both lack the POSIX compliant fmemopen function.
* The mem_stream functions step in to provide the utility of being able to read and write to an in memory location
* and maintain the familiar C stream handling idioms.
*
* @url https://pubs.opengroup.org/onlinepubs/9699919799/functions/fmemopen.html
*
*/
#ifndef MEM_STREAM_H
#define MEM_STREAM_H

#include <stdio.h>
#include <stddef.h>

/**
 * A right half open interval of characters size n [0, n) where n < 65536 ie 64K bytes
 * @note [begin, etx) is the data and [begin, end) the buffer itself.
 * Invariant: begin <= pos <= etx <= end
 */
typedef struct {
    int     flags;
    char*   begin;  /* start of the buffer and start of the text/data */
    char*   end;    /* end of the buffer */
    char*   etx;    /* end of the text/data */
    char*   pos;    /* read/write position */
} mem_file_t;

/* Opening and closing memory streams */
mem_file_t* mopen(void* buf, size_t size, const char* mode);
int mclose(mem_file_t* mstream);

/* Character input and output */
int mgetc(mem_file_t* mstream);
int mputc(int c, mem_file_t* mstream);
int mungetc(int c, mem_file_t* mstream);

/* String input and output */
char* mgets(char* buffer, int size, mem_file_t* mstream);
int mputs(const char* string, mem_file_t* mstream);

/* Block input and output */
size_t mread(void* buffer, size_t size, size_t count, mem_file_t* mstream);
size_t mwrite(const void* buffer, size_t size, size_t count, mem_file_t* mstream);

/* Positioning */
int mseek(mem_file_t* mstream, long offset, int whence);
long mtell(mem_file_t* mstream);
void mrewind(mem_file_t* mstream);
int mgetpos(mem_file_t* mstream, fpos_t* position);
int msetpos(mem_file_t* mstream, const fpos_t* position);

/* Stream state */
void mclearerr(mem_file_t* mstream);
int meof(mem_file_t* mstream);
int merror(mem_file_t* mstream);

#endif
