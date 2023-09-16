#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "blake3.h"

int main(void) {
    blake3_hasher hasher;
    blake3_hasher_init(&hasher);

    unsigned char buf[65536];

    while (1) {
        ssize_t n = read(STDIN_FILENO, buf, sizeof(buf));
        if (n < 0) {
            fprintf(stderr, "read failed: %s\n", strerror(errno));
            exit(1);
        }

        if (n == 0) {
            break; // end of file
        }

        blake3_hasher_update(&hasher, buf, n);
    }

    uint8_t output[BLAKE3_OUT_LEN];
    blake3_hasher_finalize(&hasher, output, BLAKE3_OUT_LEN);

    for (size_t i = 0; i < BLAKE3_OUT_LEN; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}
