# 4.77 MHz

The IBM PC XT ran at 4.77 MHz. This describes how to run DOSBox at XT-like speeds for programs that do not perform their own timing. Keep in mind that DOSBox cannot run at exactly 4.77 MHz. At least, not exactly the way an IBM PC XT did. You can, however, get pretty darn close by testing with some benchmark tools.

As you will see in the testing below, various types of computer instructions run at widely various speeds on the different types of computer chips out there. The most striking example is perhaps math instructions that involve real numbers such as: 1.1 x 2.2 = 2.42. This is called floating-point math. Floating-point instructions were extremely slow on the 8086 CPU unless you installed the optional 8087 co-processor. It wasn't until the Pentium age that floating-point hardware was built into all PC CPU's. Anyway, the point is that DOSBox has only one speed control, and it slows down all computer instructions by the same percentage (more or less). It is therefore not possible to tell DOSBox to slow integer math by X%, floating-point math by Y%, and non-math by Z%, etc. Near-perfect 4.77 MHz speed will not be possible until someone builds an XT emulator specifically for this purpose. This is not likely to happen because close enough will always be, quite frankly, good enough.

## Searching for 4.77 MHz (XT)

MIPS 1.10. is accurate and easy tool in the quest for 4.77 MHz.

From MIPS.DOC:``

`   FUNCTIONS:  Measures Million(s) of Instructions Per Second          (1)     General Instructions    -   random       (2)     Integer Instructions    -   ADD SUB MUL DIV       (3)     Memory to Memory        -   MOV RAM to RAM       (4)     Register to Register    -   MOV REG to REG       (5)     Register to Memory      -   MOV REG to RAM       (6)     Performance Rating      -   average ```

``

Running MIPS produces a screen similar to this:``

`       +---------------------------------------------------+       |   MIPS v1.10 CPU Benchmark and Performance Test   |   +-----------------------------------------------------------+   |          |   Million Instructions Per Second   | 10:10:00 |   +-----------------------------------------------------------+   |      BENCHMARK:      |  IBM/XT   IBM/AT   COMPAQ  |       |   |                      |  4.7Mhz    8Mhz      386   |  MIPS |   |----------------------|----------------------------|-------|   | General Instructions |   25.83     7.51     3.79  |  4.29 |   | Integer Instructions |   16.92     2.64     1.16  |  2.85 |   | Memory to Memory     |    7.79     2.40     1.34  |  1.85 |   | Register to Register |   18.07     2.35     0.98  |  3.25 |   | Register to Memory   |   20.72     6.22     3.43  |  6.39 |   |                      |                            |       |   | Performance Rating   |   18.24     4.40     2.16  |  3.72 |   +-----------------------------------------------------------+ ```

``

***Note:** If you run MIPS at too high a speed, the numbers will get large enough to screw up the formatting and make the results mostly unreadable.*

### Steps to Find 4.77 MHz

1. Download MIPS and place it in an easy-to-find folder. (I created a DOSTOOLS folder inside my DOSBOX folder.)
2. Make these changes to your [dosbox.conf](https://www.dosbox.com/wiki/Dosbox.conf) file:
3. [Launch](https://www.dosbox.com/wiki/Basic_Setup_and_Installation_of_DosBox) DOSBox. Then run MIPS from the [command line](https://www.dosbox.com/wiki/Command_Line).
4. Your goal is to get the Performance Rating in the IBM/XT column to equal 1.00. To do this, press [Ctrl-F11](https://www.dosbox.com/wiki/Special_Keys) (slow down) or [Ctrl-F12](https://www.dosbox.com/wiki/Special_Keys) (speed up) several times while watching the CPU Cycles in DOXBox’s [title bar](https://www.dosbox.com/wiki/File:Dosbox2.jpg) change from 300 to your next test value.
5. Run MIPS again. Repeat steps 4 and 5 until you get a Performance Rating of 1.00
6. Make a note of your final CPU Cycles value and set "cycles=xxx" to this value in your dosbox.conf whenever you need 4.77-MHz-like speed.

You should get something like:

*core=normal, cycles=245*``

```
       +---------------------------------------------------+       |   MIPS v1.10 CPU Benchmark and Performance Test   |   +-----------------------------------------------------------+   |          |   Million Instructions Per Second   | 10:10:00 |   +-----------------------------------------------------------+   |      BENCHMARK:      |  IBM/XT   IBM/AT   COMPAQ  |       |   |                      |  4.7Mhz    8Mhz      386   |  MIPS |   |----------------------|----------------------------|-------|   | General Instructions |    0.85     0.25     0.12  |  0.14 |   | Integer Instructions |    1.48     0.23     0.10  |  0.24 |   | Memory to Memory     |    1.02     0.31     0.18  |  0.24 |   | Register to Register |    1.35     0.18     0.07  |  0.24 |   | Register to Memory   |    0.79     0.24     0.13  |  0.24 |   |                      |                            |       |   | Performance Rating   |    1.00     0.24     0.12  |  0.22 |   +-----------------------------------------------------------+
```