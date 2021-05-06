// balance1.c --- see if parentheses are balanced in input
#include <stdio.h>
#include <stdlib.h>
#include "istack.h"
//bool balance1(char *t) {
//  istackp s = istack_new(200);
//  for(int i = 0; t[i] != '\0'; ++i) {
//    char c = t[i];
//    if(c == '(') {
//      istack_push(s, c);
//    } else if(c == ')') {
//      if(istack_isempty(s)) { return false; }
//      istack_pop(s);
//    }
//  }
//  return istack_isempty(s);
//}

bool balance1(char *t) {
    istackp s = istack_new(200);
    for (int i = 0; t[i] != '\0'; ++i) {
        char c = t[i];
        if (c == '(' || c == '{') {
            istack_push(s, c);
        } else if (c == ')') {
            if (istack_isempty(s)) { return false; }
            int pop = istack_pop(s);
            if (pop != '(') { return false; }
        } else if (c == '}') {
            if (istack_isempty(s)) { return false; }
            int pop = istack_pop(s);
            if (pop != '{') { return false; }
        }
    }
    return istack_isempty(s);
}

int main(int argc, char *argv[]) {
  for(int i = 1; i < argc; ++i) {
    printf("%s : %s\n", argv[i], balance1(argv[i])?"OK":"NG");
  }
  return 0;
}

