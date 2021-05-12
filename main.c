#include <stdio.h>
#include <stdlib.h>
#include "compiler/compiler.h"

int main(int argc, char *argv[]) {
    printf("Hello, world\n");
    int tok;
    do {
        tok = yylex();
        printlex(tok);
    } while (tok != '\n');
    return 0;
}