#ifndef BUFFER_H
#define BUFFER_H

#include "../DOS/dos_memory_types.h"
#include "../DOS/dos_error_types.h"
#include "../DOS/dos_file_types.h"
#include "../DOS/dos_file_constants.h"

typedef struct {
    dos_mem_block_t buffer;
    dos_mem_block_t peek;
    char* pos;
} buffer_t;

typedef struct {
    char read_path[DOS_MAX_PATH];
    char write_path[DOS_MAX_PATH];
    dos_file_handle_t read_handle;
    dos_file_handle_t write_handle;
    dos_file_position_t read_pos;
    dos_file_position_t write_pos;
    buffer_t mem;
} file_buffer_t;

dos_memsize_t buffer_query_max_free();

dos_error_code_t buffer_request(buffer_t* buffer, dos_memsize_t desired_size);

dos_error_code_t buffer_release(buffer_t* buffer);

dos_error_code_t file_buffer_read_open(file_buffer_t* file_buffer, char* filepath);

dos_error_code_t file_buffer_read_close(file_buffer_t* file_buffer);

dos_error_code_t file_buffer_write_open(file_buffer_t* file_buffer, char* filepath);

dos_error_code_t file_buffer_write_close(file_buffer_t* file_buffer);

dos_error_code_t file_buffer_write_all(file_buffer_t* file_buffer);

dos_error_code_t file_buffer_read_all(file_buffer_t* file_buffer);

#endif
