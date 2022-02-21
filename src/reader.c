#include <stdlib.h>
#include <stdio.h>

void invert_bytes (void* src, size_t size) {
    char* ptr = (char*) src;

    size_t cnt = size / 2 - (size % 2);

    for (size_t i = 0; i < cnt; i++) {
        char tmp = ptr[i];
        ptr[i] = ptr[size-1-i];
        ptr[size-1-i] = tmp;
    }
}

void read (const char* filename) {
    FILE* file = fopen(filename, "rb");

    if (!file) {
        printf("Could not read %s.\n", filename);
        return;
    }

    // Verify signature (https://en.wikipedia.org/wiki/Portable_Network_Graphics#File_header)

    unsigned long signature;

    fread(&signature, 8, 1, file);

    if (signature != 0x0a1a0a0d474e5089) {
        printf("File is not in PNG format.\n");
        return;
    }

    // Read chunks (https://en.wikipedia.org/wiki/Portable_Network_Graphics#Critical_chunks)

    // Skip IHDR length & type

    fseek(file, 8, SEEK_CUR);

    // Get file resolution
    
    unsigned int width, height;
    
    fread(&width, 4, 1, file);
    invert_bytes(&width, 4);
    fread(&height, 4, 1, file);
    invert_bytes(&height, 4);

    // Skip to next chunk

    fseek(file, 5 + 4, SEEK_CUR);

    // Find and read IDAT chunk length and type

    unsigned int info[2] = {0,0};
    
    while (1) {
        fread(&info, 4, 2, file);
        invert_bytes(&info[0], 4);
        if (info[1] != 0x54414449) {
            fseek(file, info[0] + 4, SEEK_CUR);
        }
        else break;
    }

    // Read IDAT data.

    unsigned char data[info[0]];
    fread(&data, 1, info[0], file);

    fclose(file);

}

int main () {
    char name[] = "../test/compressed.png";
    read(name);
    return 0;
}