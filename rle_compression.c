#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Compress input file to output file using simple RLE:
   Format written: <char><count><space> ... (last pair may have no trailing space)
   For example: a5 b3 \n1 -> means 'a' repeated 5, 'b' repeated 3, newline once.
*/
void compress_file(const char *inname, const char *outname) {
    FILE *in = fopen(inname, "rb");
    if (!in) { printf("Cannot open %s\n", inname); return; }
    FILE *out = fopen(outname, "wb");
    if (!out) { fclose(in); printf("Cannot create %s\n", outname); return; }

    int prev = fgetc(in);
    if (prev == EOF) { fclose(in); fclose(out); return; }
    unsigned long count = 1;
    int cur;

    while ((cur = fgetc(in)) != EOF) {
        if (cur == prev && count < 4294967295u) {
            /* same character, increase run length */
            count++;
        } else {
            /* write previous char and its count */
            fputc(prev, out);
            fprintf(out, "%lu ", count);
            prev = cur;
            count = 1;
        }
    }
    /* write last run (no trailing space required but we put none after last) */
    fputc(prev, out);
    fprintf(out, "%lu", count);

    fclose(in);
    fclose(out);
    printf("Compressed to %s\n", outname);
}

/* Decompress file previously compressed by above format */
void decompress_file(const char *inname, const char *outname) {
    FILE *in = fopen(inname, "rb");
    if (!in) { printf("Cannot open %s\n", inname); return; }
    FILE *out = fopen(outname, "wb");
    if (!out) { fclose(in); printf("Cannot create %s\n", outname); return; }

    int c;
    while ((c = fgetc(in)) != EOF) {
        int ch = c;            /* the character representing the run */
        unsigned long count = 0;
        int d = fgetc(in);     /* next char should start the count (digits or space) */

        /* Skip any spaces until a digit (robustness) */
        while (d != EOF && isspace(d)) {
            d = fgetc(in);
        }
        /* Read count number (decimal) */
        while (d != EOF && isdigit(d)) {
            count = count * 10 + (d - '0');
            d = fgetc(in);
        }
        /* If no digits found, assume count 1 */
        if (count == 0) count = 1;

        /* Write 'ch' count times */
        for (unsigned long i = 0; i < count; ++i) fputc(ch, out);

        if (d != EOF) ungetc(d, in); /* put back last read char for next iteration */
    }

    fclose(in);
    fclose(out);
    printf("Decompressed to %s\n", outname);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage:\n");
        printf("  %s c input.txt output.rle   # compress\n", argv[0]);
        printf("  %s d input.rle output.txt   # decompress\n", argv[0]);
        return 1;
    }
    if (argv[1][0] == 'c') compress_file(argv[2], argv[3]);
    else if (argv[1][0] == 'd') decompress_file(argv[2], argv[3]);
    else printf("Unknown mode '%s'\n", argv[1]);
    return 0;
}
