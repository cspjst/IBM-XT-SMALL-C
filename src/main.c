#include <stdio.h>
#include "DOS/dos_error.h"
#include "DOS/dos_error_codes.h"
#include "DOS/dos_memory_constants.h"
#include "SMALLC/buffer.h"

#define USAGE "usage: smallc <input_file> <output_file>\n"

int main(int argc, char* argv[]) {
    switch(argc) {
        case 3:
            printf("%s %s %s\n", argv[0], argv[1], argv[2]);
            printf("Max free = %liK\n", buffer_query_max_free() / DOS_MEM_SIZE_1K);
            return 0;
        default:
            dos_perror(argv[argc - 1], DOS_INVALID_FORMAT);
            fprintf(stderr, USAGE);
            return 1;
    }
}
