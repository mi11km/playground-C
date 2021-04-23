#include <stdio.h>
#include <string.h>

char *findfirst(char *str, char *sub) {
    char *a, *b;
    if (*sub == 0) {
        return str;
    }
    for (; *str != 0; str += 1) {
        if (*str != *sub) {
            continue;
        }
        a = str;
        b = sub;
        for (; *b != 0; b++) {
            if(*a != *b) {
                break;
            }
            a++;
        }
        if (*b == 0) {
            return str;
        }
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    char *s1, *s2, *s;

    s1 = argv[1];
    s2 = argv[2];
    if ((s = findfirst(s1, s2))) {
        printf("%s\n", s);
    } else {
        printf("\n");
    }
    return 0;
}