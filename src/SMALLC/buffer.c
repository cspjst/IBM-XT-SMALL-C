#include "buffer.h"
#include "../DOS/dos_memory_constants.h"
#include "../DOS/dos_memory_services.h"
#include "../DOS/dos_error_codes.h"

dos_memsize_t buffer_query_max_free() {
    unsigned short size;
    if(dos_get_free_memory_paragraphs(&size) != DOS_SUCCESS) return 0;
    return size * DOS_PARAGRAPH_SIZE;
}

dos_error_code_t buffer_request(buffer_t* buffer, dos_memsize_t desired_size) {
    dos_error_code_t e = dos_allocate_memory_blocks(, &buffer->buffer.begin.parts.segment);
}

dos_error_code_t buffer_release(buffer_t* buffer) {

}
