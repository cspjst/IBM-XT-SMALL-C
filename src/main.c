#include <stdio.h>

#define USAGE "usage: smallc <input_file> <output_file>\n"

int main(int argc, char* argv[]) {
    switch(argc) {
        case 3:
            printf("%s %s %s", argv[0], argv[1], argv[2]);
            return 0;
        default:
            //dos_perror(argv[argc - 1], DOS_INVALID_FORMAT);
            fprintf(stderr, USAGE);
            return 1;
    }
}
