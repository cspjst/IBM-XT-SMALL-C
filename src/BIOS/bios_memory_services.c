/**
* @author      Jeremy Simon Thornton
* @copyright   2024 Jeremy Simon Thornton
*
*/
#include "bios_memory_services.h"

unsigned short bios_get_startup_memory_kb() {
    __asm {
        .8086
        int     BIOS_MEMORY_SERVICES    ; Returns KB of base memory in AX
    }
}
