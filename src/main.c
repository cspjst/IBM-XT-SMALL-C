#include <stdio.h>
#include <string.h>
#include <errno.h>

static char buffer[] = "foobar";

int main() {

    int ch;
        FILE *stream;


        stream = fmemopen(buffer, strlen (buffer), "r");
        if (stream == NULL) perror("ERROR: ");

        while ((ch = fgetc(stream)) != EOF) printf("Got %c\n", ch);

        fclose(stream);
        return 0;

}
