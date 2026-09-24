/**
* @author       Jeremy Simon Thornton
* @copyright    2026 Jeremy Simon Thornton
*
* @note For DOS binary mode is essential.
* It disables text mode translations e.g.
* + '\n' translated to "\r\n" on disk.
* + Ctrl-Z treated as an end-of-file marker.
* Therefore, file positions and byte counts can differ from the actual bytes on disk.
* Disabling such translations is essential for any exact byte-level file access e.g.
* images, executables, archives, serialized data.
*/
#ifndef STREAM_FLAGS_H
#define STREAM_FLAGS_H

/**
 * Mode	Read	Write	Creates	Truncates	Initial position
 * "r" 	 Yes	   No	     No	       No	Beginning
 * "w" 	  No	  Yes	    Yes	      Yes	Beginning
 * "a" 	  No	  Yes	    Yes	       No	End for writes
 * "r+"	 Yes	  Yes	     No	       No	Beginning
 * "w+"	 Yes	  Yes	    Yes	      Yes	Beginning
 * "a+"	 Yes	  Yes	    Yes	       No	End for writes
 * @note 'b' can be added to any mode, and sets IO_BINARY
 */
#define IO_RDONLY     0x0001
#define IO_WRONLY     0x0002
#define IO_RDWR       0x0003
#define IO_CREATE     0x0004
#define IO_TRUNCATE   0x0008
#define IO_APPEND     0x0010
#define IO_BINARY     0x0020    /* No DOS text translation*/

#define IO_UNBUF      0x0040    /* Unbuffered stream */
#define IO_SYSBUF     0x0080    /* System allocated the buffer */
#define IO_EOF        0x0100    /* End-of-file has been encountered */
#define IO_ERR        0x0200    /* An I/O error occurred */
#define IO_STRING     0x0300    /* Stream refers to a string/memory buffer */

/* Helper functions */
int stream_mode_to_flags(const char* mode);

#endif
