#include "stream_flags.h"

#include <stdint.h>
#include <errno.h>

/* Little endian mode chars as an uint32_t */
#define MODE_R    0x72UL          /* "r\0" */
#define MODE_W    0x77UL          /* "w\0" */
#define MODE_A    0x61UL          /* "a\0" */
#define MODE_RP   0x2B72UL        /* "r+" */
#define MODE_WP   0x2B77UL        /* "w+" */
#define MODE_AP   0x2B61UL        /* "a+" */

#define MODE_RB    0x6272UL       /* "rb" */
#define MODE_WB    0x6277UL       /* "wb" */
#define MODE_AB    0x6261UL       /* "ab" */
#define MODE_RPB   0x622B72UL     /* "r+b" */
#define MODE_WPB   0x622B77UL     /* "w+b" */
#define MODE_APB   0x622B61UL     /* "a+b" */
#define MODE_RBP   0x2B6272UL     /* "rb+" */
#define MODE_WBP   0x2B6277UL     /* "wb+" */
#define MODE_ABP   0x2B6261UL     /* "ab+" */

int stream_mode_to_flags(const char* mode) {
    uint32_t packed = 0;
    int i;

    if(!mode) {
        errno = EINVAL;
        return -1;
    }

    for (i = 0; i < 4 && mode[i] != '\0'; i++)
        packed |= (uint32_t)(unsigned char)mode[i] << (8 * i);

    switch (packed) {
        case MODE_RB: return IO_RDONLY | IO_BINARY;
        case MODE_R: return IO_RDONLY;
        case MODE_WB: return IO_WRONLY | IO_CREATE | IO_TRUNCATE | IO_BINARY;
        case MODE_W: return IO_WRONLY | IO_CREATE | IO_TRUNCATE;
        case MODE_AB: return IO_WRONLY | IO_CREATE | IO_APPEND | IO_BINARY;
        case MODE_A: return IO_WRONLY | IO_CREATE | IO_APPEND;
        case MODE_RPB:
        case MODE_RBP: return IO_RDWR | IO_BINARY;
        case MODE_RP: return IO_RDWR;
        case MODE_WPB:
        case MODE_WBP: return IO_RDWR | IO_CREATE | IO_TRUNCATE | IO_BINARY;
        case MODE_WP: return IO_RDWR | IO_CREATE | IO_TRUNCATE;
        case MODE_APB:
        case MODE_ABP: return IO_RDWR | IO_CREATE | IO_APPEND | IO_BINARY;
        case MODE_AP: return IO_RDWR | IO_CREATE | IO_APPEND;
        default: errno = EINVAL;
    }

    return -1;
}
