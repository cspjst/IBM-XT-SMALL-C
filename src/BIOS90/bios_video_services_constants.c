/**
 * @author      Jeremy Simon Thornton
 * @copyright   2024 Jeremy Simon Thornton
 *
 */
#include "bios_video_services_constants.h"

const char bios_video_mode_names[20][64] = {
    "00  40x25 B/W text (CGA)",
    "01  40x25 16 color text (CGA)",
    "02  80x25 16 shades of gray text (CGA)",
    "03  80x25 16 color text (CGA)",
    "04  320x200 4 color TV graphics (CGA)",
    "05  320x200 4 color RGB graphics (CGA)",
    "06  640x200 B/W graphics (CGA)",
    "07  80x25 Monochrome text (MDA,HERC)",
    "08  160x200 16 color graphics (PCjr)",
    "09  320x200 16 color graphics (PCjr)",
    "0A  640x200 4 color graphics (PCjr)",
    "0B  Reserved (EGA BIOS function 11)",
    "0C  Reserved (EGA BIOS function 11)",
    "0D  320x200 16 color graphics (EGA)",
    "0E  640x200 16 color graphics (EGA)",
    "0F  640x350 Monochrome graphics (EGA)",
    "10  640x350 16 color graphics (EGA)",
    "11  640x480 B/W graphics (MCGA)",
    "12  640x480 16 color graphics (VGA)",
    "13  320x200 256 color graphics (MCGA, VGA)"
};
