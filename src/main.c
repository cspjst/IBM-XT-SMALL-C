#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "BIOS/bios_clock_services.h"
#include "BIOS/bios_clock_types.h"
#include "BIOS/bios_clock_constants.h"

#include "DOS/dos_file_tools.h"

#define USAGE "usage: test <file_path> <buffer_size>\nERROR"

int main(int argc, char* argv[]) {
    errno = EINVAL;
    if(argc != 3) goto error;
    bios_ticks_since_midnight_t t1, t2;
    dos_file_size_t sz = dos_get_file_size(argv[1]);
    int type, k = atoi(argv[2]);
    type = (k) ? _IOFBF : _IONBF;
    printf(" buffer %s = %iK file %s = %li bytes %0.2fK\n", type == _IOFBF ?"yes" :"no",k, argv[1], sz, (float)sz / 1024.0);
    k *= 1024;
    char* buf = (char*)malloc(k);

    FILE* f = fopen(argv[1], "r+");
    if(!f) goto error;
    if(setvbuf(f, buf, type, k) != 0) goto error;

    bios_read_system_clock(&t1);

    while(!feof(f)) {
        fgetc(f);
        //printf("%c",fgetc(f));
    }

    bios_read_system_clock(&t2);
    fclose(f);

    printf("elapsed ticks %li - %li = %li i.e. %0.3f seconds", t2, t1, t2 - t1, (float)(t2 - t1) / BIOS_TICKS_PER_SECOND);
    free(buf);
    return 0;

error:
    perror(USAGE);
    return 1;
}
