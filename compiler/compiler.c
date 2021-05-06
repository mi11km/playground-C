#include "compiler.h"
#include <ctype.h>

#define INTNUM 300

int ch = ' ';
int yylval;
int yylex() {
    int t;
    while (ch == ' ') ch = getchar();
    if (isdigit(ch)) {
        t = ch - '0';
        while (isdigit(ch = getchar())) t = t * 10 + ch - '0';
        yylval = t;
        return INTNUM;
    } else if (ch == '+') {
        ch = getchar();
        return '+';
    } else if (ch == '*') {
        ch = getchar();
        return '*';
    } else if (ch == EOF) {
        return EOF;
    } else {
        if (ch != '\n') {
            fprintf(stderr, "Illegal character.\n");
        }
        ch = ' ';
        return '\n';
    }
}

//int tok;
void printlex(int tok) {
    if (tok == '+') {
        printf("tok = '+'\n");
    } else if (tok == '*') {
        printf("tok  '*'\n");
    } else if (tok == INTNUM) {
        printf("tok = INTNUM, yylval = %d\n", yylval);
    } else if (tok == '\n') {
        printf("tok = '\\n'\n");
    } else if (tok == EOF) {
        printf("tok = EOF\n");
    } else {
        printf("tok = ???\n");
    }
}

//int main(int argc, char *argv[]) {
//    do {
//        tok = yylex();
//        printlex();
//    } while (tok != '\n');
//    return 0;
//}