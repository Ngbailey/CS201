#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    if (argc < 4) {
        fprintf(stderr, "Missing arguments\n");
        return -1;
    }

    // Check if buffer is valid before reading anything
    int bufferSize = atoi(argv[3]);
    if (bufferSize < 1) {
        fprintf(stderr, "Invalid buffer size: %s\n", argv[3]);
        return -1;
    }

    printf("*** Copying from '%s' to '%s' (Buffer size: %dB) ***\n",
        argv[1], argv[2], bufferSize);

    // READ SOURCE FILE
    FILE* inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        fprintf(stderr, "Error opening source file %s: %s\n",
            argv[1], strerror(errno));
        return -1;
    }

    // READ DESTINATION FILE
    FILE* outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        fprintf(stderr, "Error opening destination file %s: %s\n",
            argv[2], strerror(errno));
        return -1;
    }

    int buffer[bufferSize];
    int bytes;
    while ((bytes = fread(buffer, 1, bufferSize, inputFile)) != 0) {
        if (fwrite(buffer, 1, bytes, outputFile) != bytes) {
            fprintf(stderr, "Error writing into destination file: %s\n", strerror(errno));
            return -1;
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}