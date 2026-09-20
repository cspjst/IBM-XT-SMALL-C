| Switch | Setting       | Meaning                                                      |
| :----- | :------------ | :----------------------------------------------------------- |
| 1      | Off           | Normal POST then boot                                        |
| 1      | **On**        | Continuous power-on self-test (POST) - used for burn-in testing only |
| 2      | Off           | 8087 math coprocessor installed                              |
| 2      | **On**        | 8087 math coprocessor **NOT** installed                      |
| 3,4    | **On**,**On** | One bank of memory                                           |
| 3,4    | Off,**On**    | Two banks of memory                                          |
| 3,4    | **On**,Off    | Three banks of memory                                        |
| 3,4    | Off,Off       | Four banks of memory                                         |
| 5,6    | Off,Off       | MDA or Hercules video                                        |
| 5,6    | Off,**On**    | 40-column CGA video                                          |
| 5,6    | **On**,Off    | 80-column CGA video                                          |
| 5,6    | **On**,**On** | No video or special (like EGA or VGA)*                       |
| 7,8    | **On**,On     | 1 floppy drive                                               |
| 7,8    | Off,**On**    | 2 floppy drives                                              |
| 7,8    | **On,**Off    | 3 floppy drives                                              |
| 7,8    | Off,Off       | 4 floppy drives                                              |

\* The reason why this is specified as 'No video' is because with MDA, Hercules or CGA graphics, the system's ROM BIOS handles all video communications, whereas in the more advanced graphics standards (EGA and VGA), these cards have their own dedicated ROM BIOS which software uses to communicate with the video card. So in such a scenario, the system's BIOS needs to have its built-in video communications "switched off".