#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "SMALLC/stream_flags.h"

int main() {

    printf("%X\n",stream_mode_to_flags("r"));
    printf("%X\n",stream_mode_to_flags("w"));
    printf("%X\n",stream_mode_to_flags("a"));
    printf("%X\n",stream_mode_to_flags("r+"));
    printf("%X\n",stream_mode_to_flags("w+"));
    printf("%X\n",stream_mode_to_flags("a+"));
    return 0;
}
