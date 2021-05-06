// postfix1.c -- convert infix to postfix (w/o parentheses)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "istack.h"
int operprec(int c) {
  switch(c) {
    case '+': case '-': return 1;
    case '*': case '/': case '%': return 2;
    case '^': return 3;
    default: return 0;
  }
}
void postfix1(char *t, char *u) {
  istackp s = istack_new(200);
  for(int i = 0; t[i] != '\0'; ++i) {
    char c = t[i];
    if(isdigit(c)) { *u++ = c; continue; }
    while(!istack_isempty(s) &&
          operprec(istack_top(s)) >= operprec(c)) {
      *u++ = istack_pop(s);
    }
    istack_push(s, c);
  }
  while(!istack_isempty(s)) { *u++ = istack_pop(s); }
  *u++ = '\0';
}
int main(int argc, char *argv[]) {
  char buf[200];
  for(int i = 1; i < argc; ++i) {
    postfix1(argv[i], buf);
    printf("%s => %s\n", argv[i], buf);
  }
  return 0;
}
