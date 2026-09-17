/* ---------------------------------------------------------------
   lexer_test.c

   Token-coverage source for IBM XT SMALL-C, Stage 1 (lexer).
   Not meant to run or even parse yet -- just meant to be fed
   character-by-character into get_token() and checked against
   what it SHOULD produce, token by token.

   Lines marked "CHECK" use a construct that may or may not be in
   Hendrix's Small-C subset -- verify against the book and strip
   out anything that isn't, before this file becomes a parser
   test too.

   Also worth deciding before writing get_token(): do the #define
   lines get handled by a separate preprocessing pass before the
   main tokenizer ever sees them, or does the lexer itself
   special-case a line starting with '#'? Small-C-era compilers
   usually did the former -- a thin macro-substitution pass over
   the text, or over the token stream, ahead of the real lexer.
   --------------------------------------------------------------- */

#define TRUE     1
#define FALSE    0
#define MAXLINE  80
#define NEWLINE  '\n'
#define PROMPT   "> "
#define GREETING "hi\n"

/* comment content with characters that look like operators, to
   make sure the lexer doesn't get confused by what's inside a
   comment: 3/4 * 2 == not a division or multiplication */

int  count;
char buffer[MAXLINE];

int add(a, b)
int a, b;
{
    return a + b;
}

int main()
{
    int  x, y, z;
    char *p;
    char  c;

    x = 10;
    y = -3;                /* unary minus next to a number literal */
    z = add(x, y);

    if (z >= 0 && z <= MAXLINE)
        count = count + 1;
    else
        count = 0;

    if (!count)
        count = 1;

    while (x > 0) {
        x = x - 1;
        if (x == 5)
            continue;       /* CHECK: continue in Hendrix's subset? */
        if (x == 1)
            break;
    }

    for (y = 0; y < 10; y = y + 1) {
        buffer[y] = 'a' + y;
    }

    p = buffer;
    c = *p;
    p = p + 1;

    if (x != y)
        z = 0;

    x = x << 1;
    x = x >> 1;
    x = x & 0x0F;           /* CHECK: 0x hex literals in the original? */
    x = x | 1;
    x = x ^ 1;
    x = ~x;

    z = x<y;                /* no spaces around operators -- lookahead test */
    z = x<=y;
    z = x<<y;

    x++;
    y--;

    c = NEWLINE;
    p = PROMPT;

    return TRUE;
}
