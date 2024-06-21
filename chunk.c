#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

char input[] = "2+2+2+2";
char chunks[MAXLEN][MAXLEN];
int chunks_idx = 0;
char chunk[MAXLEN];
int chunk_idx = 0;

void init_chunk(void)
{
    for (int i = 0; i < MAXLEN; i++) {
        chunk[i] = '\0';
    }
    chunk_idx = 0;
    printf("Chunk [%d] initialized\n", chunk_idx);
}

void populate_chunks(void)
{
    printf("Populating chunk [%d]\n", chunks_idx);
    strcpy(chunks[chunk_idx], chunk);
    printf("Populated chunk [%d]\n", chunks_idx);
    for (int i = 0; chunk[i] != '\0'; i++)
        printf("Chunk [%d] %c\n", chunk_idx, chunk[i]);
    init_chunk();
    chunks_idx++;
}

int main(void)
{
    int op_cnt = 0;
    init_chunk();
    for (int i = 0; input[i] != '\0'; i++) {
        printf("\nNEW INPUT CHAR [%d] %c\n", i, input[i]);
        if (isdigit(input[i])) {
            chunk[chunk_idx] = input[i];
            chunk_idx++;
        } else if (input[i] == '+') {
            if (!op_cnt) {
                chunk[chunk_idx] = input[i];
                chunk_idx++;
                op_cnt++;
            } else if (op_cnt) {
                populate_chunks();
                chunk[chunk_idx] = input[i];
                chunk_idx++;
            }
        }
    }
    populate_chunks();
    for (int i = 0; i < chunk_idx; i++)
        printf("OUTPUT [%d] %s", i, chunks[i]);
    return 0;
}
