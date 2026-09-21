#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "BIOS/bios_clock_services.h"
#include "BIOS/bios_clock_types.h"
#include "BIOS/bios_clock_constants.h"

#define USAGE   "usage: test <file_path> <buffer_size> <file_size>\nERROR"
#define WARNING "WARNING: %s already exists, okay to overwrite? y/n "
#define YES     'y'
#define RAM1K   1024

unsigned long file_size(FILE* f) {
    fseek(f, 0L, SEEK_END);
    unsigned long sz = ftell(f);
    rewind(f);
    return sz;
}

int write_test(char* file_path, unsigned long k, unsigned long sz) {
    bios_ticks_since_midnight_t t1, t2;
    int type = (k) ? _IOFBF : _IONBF;

    FILE* f = fopen(file_path, "w");
    if(!f) return 1;
    sz *= RAM1K;
    k *= RAM1K;
    char* buf = (char*)malloc(k);
    if(setvbuf(f, buf, type, k) != 0) goto error;

    bios_read_system_clock(&t1);
    while(--sz) fputc('!', f);
    bios_read_system_clock(&t2);

    fclose(f);

    printf("%0.2f,", (float)(t2 - t1) / BIOS_TICKS_PER_SECOND);
    free(buf);
    return 0;

error:
    fclose(f);
    free(buf);
    return 1;
}

int read_test(char* file_path, unsigned long k) {
    bios_ticks_since_midnight_t t1, t2;
    int type = (k) ? _IOFBF : _IONBF;

    FILE* f = fopen(file_path, "r");
    if(!f) return 1;

    unsigned long sz = file_size(f);
    if(sz == 0) goto error;
    k *= RAM1K;
    char* buf = (char*)malloc(k);
    if(setvbuf(f, buf, type, k) != 0) goto error;

    bios_read_system_clock(&t1);
    while(!feof(f)) fgetc(f);
    bios_read_system_clock(&t2);

    fclose(f);

    printf("%0.2f,", (float)(t2 - t1) / BIOS_TICKS_PER_SECOND);
    free(buf);
    return 0;

error:
    fclose(f);
    free(buf);
    return 1;
}

int main(int argc, char* argv[]) {
    if(argc != 4) goto error;

    errno = EINVAL;
    struct stat fstats;


    if(stat(argv[1], &fstats) != 0) {
        if(write_test(argv[1], atoi(argv[2]), atoi(argv[3])) != 0) goto error;
        if(read_test(argv[1], atoi(argv[2])) != 0) goto error;
        if(remove(argv[1]) != 0) goto error;
        return 0;
    }

    fprintf(stderr, WARNING, argv[1]);
    if((char)getchar() == YES) {
        if(write_test(argv[1], atoi(argv[2]), atoi(argv[3])) != 0) goto error;
    }
    if(read_test(argv[1], atoi(argv[2])) != 0) goto error;
    return 0;

error:
    perror(USAGE);
    return 1;

}
