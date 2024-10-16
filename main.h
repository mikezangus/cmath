#ifndef MAIN_H
#define MAIN_H

#define NUM_MAXLEN 26
#define STR_MAXLEN 100

#define DASHES "-------------------------"

typedef struct Bounds {
    char* l;
    char* r;
} Bounds;

void clean_input(char* s);
void enter_workflow(char* s);
void insert_parens(char* s);

#endif // MAIN_H
