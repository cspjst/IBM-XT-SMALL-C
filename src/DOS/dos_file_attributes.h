/**
* @author      Jeremy Simon Thornton
* @copyright   2024, 2025, 2026 Jeremy Simon Thornton
*
* DOS File Attributes
* Directory Attribute Flags
*
* |7|6|5|4|3|2|1|0| Directory Attribute Flags
* | | | | | | | `--- 1 = read only
* | | | | | | `---- 1 = hidden
* | | | | | `----- 1 = system
* | | | | `------ 1 = volume label  (exclusive)
* | | | `------- 1 = subdirectory
* | | `-------- 1 = archive
* `----------- unused
*
* Directory Time Format
*
* |F|E|D|C|B|A|9|8|7|6|5|4|3|2|1|0| Directory Time Format
* | | | | | | | | | | | `----------- seconds (2 second increments)
* | | | | | `---------------------- minutes (0-59)
* `------------------------------- hours (0-23)
*
* Directory Date Format
*
* |F|E|D|C|B|A|9|8|7|6|5|4|3|2|1|0| Directory Date Format
* | | | | | | | | | | | `----------- Day (1-31)
* | | | | | | | `------------------ Month (1-12)
* `------------------------------- Year (less 1980)
*
* @note - with respect to the findfirst() and findnext() functions normal iles are always included
* along with the requested attributes except when the LABEL attribute is requested.
* It's up to the programmer to determine which files are match the requested attributes.
*
*/
