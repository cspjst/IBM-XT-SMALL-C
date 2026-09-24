/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
*  @url https://stanislavs.org/helppc/file_handles.html
*/
#ifndef DOS_FILE_CONSTANSTS_H
#define DOS_FILE_CONSTANSTS_H

/*  As per Microsoft MS-DOS programmer's reference 1993 */
#define DOS_MAX_PATH        64

/* DOS Default/Predefined File Handles */
#define DOS_STDIN_HANDLE    0   /* 0 - Standard Input Device - can be redirected (STDIN) */
#define DOS_STDOUT_HANDLE   1   /* 1 - Standard Output Device - can be redirected (STDOUT) */
#define DOS_STDERR_HANDLE   2   /* 2 - Standard Error Device - can be redirected (STDERR) */
#define DOS_STDAUX_HANDLE   3   /* 3 - Standard Auxiliary Device (STDAUX) */
#define DOS_STDPRN_HANDLE   4   /* 4 - Standard Printer Device (STDPRN) */






#endif
