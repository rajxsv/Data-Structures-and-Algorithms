#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        perror("malloc failed");
        return 1;
    }
    printf("address of p is %p with pid = %08x\n", (void *)p, getpid());

    return 0;
}
