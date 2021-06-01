// searchrec.c --- search path with recursion
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "railmap2.h"

void search(int cur, int goal, int len) {
    if (map[cur].visit) { return; }
    map[cur].visit = true;
    if (cur == goal) {
        printf("len = %d\n", len);
        return;
    }
    for (int i = 0; i < map[cur].num; ++i) {
        int k = map[cur].edge[i];
        if (map[k].visit == false) {
            map[k].prev = cur;
            search(k, goal, len + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    int from = atoi(argv[1]), to = atoi(argv[2]);
    search(from, to, 0);
    istackp stations = istack_new(13);
    istack_push(stations, to);
    while (map[istack_top(stations)].prev != -1) {
        istack_push(stations, map[istack_top(stations)].prev);
    }
    while (!istack_isempty(stations)) {
        printf("%s ", map[istack_pop(stations)].name);
    }
    printf("\n");
    return 0;
}
