#include <stdio.h>
#include "itbl.h"

int main(){
    itblp tree = itbl_new();
    itbl_put(tree, 5, 5);
    itbl_put(tree, 1, 1);
    itbl_put(tree, 3, 3);
    itbl_put(tree, 9, 9);
    printf("%d\n", itbl_get(tree, 9));
    return 0;
}