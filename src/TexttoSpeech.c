/*
  Command to compile :- gcc -Wall -g -o flite_test flite_test.c -lflite_cmu_us_slt -lflite_usenglish -lflite_cmulex -lflite -lm -lasound
*/

#include <flite/flite.h>
#include <stdio.h>
#include <stdlib.h>

register_cmu_us_slt();

int main(int argc, char **argv)
{
    cst_voice *v;

    flite_init();

    v = register_cmu_us_slt(NULL);

    /* File handling in c */
    FILE *fptr = fopen("example.txt", "rb");
    fseek(fptr, 0, SEEK_END);
    long fsize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char *text = malloc(fsize+1);
    fread(text, fsize, 1, fptr);

    // printf("%s\n", text);

    flite_text_to_speech(text,v,"play");

}
