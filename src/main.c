#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "SMALLC/mem_stream.h"

int main() {

    char text[] = "Hello World!";

    mem_file_t* m = mopen(text, sizeof(text) - 1, "r");
    printf("%c\n", *m->begin);
    printf("%c\n", *m->end);
    printf("%c\n", *m->pos);
    printf("%c\n", *m->etx);

    return 0;
}
