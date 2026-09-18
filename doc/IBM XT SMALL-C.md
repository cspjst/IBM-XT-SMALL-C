# IBM XT SMALL-C

A self-hosting Small-C compiler for the IBM PC XT, following James E. Hendrix's *The Small-C Handbook* (1984) as the reference implementation. Gen0 is built with Open Watcom (cross-compiled from macOS via CMake, `-0` 8086 target) and used to compile the compiler's own source, producing a gen1 binary that runs natively under DOS on real 8088 hardware — verified by diffing gen1/gen2 output for a fixed point. Development loop is Zed → Watcom → DOSBox-X tuned to XT timing, with periodic validation on physical XT hardware. Once self-hosting is solid, the project moves beyond Hendrix's direct-to-assembly design to layer in an AST and basic optimisation passes, as a way of learning modern compiler construction from inside a period-correct 8086 toolchain.

**Stage 0 — Toolchain and feedback loop (before any compiler code)**

- CMake toolchain file targeting Open Watcom cross-compiling to 8086/DOS, with `-0` baked into `CMAKE_C_FLAGS` so it's not something you have to remember per-build. Worth noting Watcom's CMake support has historically been a bit rough around the edges compared to gcc/clang toolchain files — check the actual `wcc`/`wlink` command lines CMake generates the first few times rather than trusting it blind.
- DOSBox-X configured for real 8088 cycle-accurate timing, not the default fast-PC preset — this becomes your fast inner loop.
- Script the loop: build → drop binary into DOSBox-X's mounted dir → run → pull result back out. That scriptability is what makes hundreds of iterations tolerable.
- Bare metal on the two XTs is a periodic checkpoint, not the daily loop — floppy or serial transfer, whatever your current hardware state supports.
- Prove this whole pipeline with a trivial hand-assembled "hello world" before a line of compiler exists, so when something breaks later you know it's the compiler and not the harness.

**Stage 1 — Gen0: Hendrix's Small-C, built by Watcom**

- Lexer + recursive-descent parser emitting 8086 asm directly, no IR, following the book's structure.
- Discipline point that matters more than it looks: write this source in the Small-C subset from day one, even though Watcom (not your compiler) is what actually builds it here. That source has to survive being fed to itself in Stage 2 — if you lean on C99 conveniences now, you're rewriting later.
- Minimal runtime (INT 21h console I/O, basically).
- Validate against the book's own test programs, DOSBox-X first, spot-checked on real hardware.

**Stage 2 — Self-hosting proof**

- gen0 compiles the compiler's own source → gen1.
- gen1 compiles the same source → gen2.
- Diff gen1 and gen2's generated assembly. Match means fixed point — actual self-hosting, not a one-off fluke.
- gen1 now has to run and operate standalone in the DOS/640K environment, which is the first point it's tested on its own merits rather than Watcom's.

**Stage 3 — Fully native on the XT**

- Open question worth settling before you get here: does "runs natively" include your own assembler/linker eventually, or does gen1 permanently hand off to Watcom's `wasm`/`wlink` (or something period-correct like MASM)? Changes what self-hosting actually means end to end.
- Confirm the edit/compile/link cycle could happen entirely on XT hardware in principle, even if day-to-day you're still editing in Zed.

**Stage 4 — Modern techniques, once gen1/gen2 parity is solid**

- Real AST rather than direct-to-asm emission, then passes on top of it — constant folding, dead code elimination, maybe peephole optimisation on the generated asm.
- Decide early whether this evolves the self-hosting line in place, or forks off a "v2" so the Hendrix-faithful gen1 stays intact as a milestone rather than getting quietly mutated away.

## Error Reporting

Error reporting for `macro_pass` (and later stages) follows `file:line: error|warning: message` on stderr, in the standard Unix convention, with errors and warnings tracked by separate counters rather than exiting on the first problem. Recoverable issues — a malformed `#define` line, a macro redefined with a different body, an unsupported directive like `#include` encountered early — are reported and skipped, letting the pass continue and surface every problem in one run. Fatal issues — unable to open the input or output file, the macro table full, or a comment/string literal still open at EOF — report immediately (pointing at the line the construct started, not where EOF was hit) and halt, since continuing has no sane recovery. A partially-written `.i` file is deleted on fatal failure so a stale half-built output can never be mistaken for valid input by a later stage. `main()` reports a final error/warning summary and sets `TEST.EXE`'s exit code from the error count. Implemented as a small `error.h`/`error.c` (`report_error`, `report_warning`, `error_count`) rather than a full diagnostics engine — proportionate to this stage, not Clang-grade.