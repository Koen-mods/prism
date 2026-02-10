#include "lexer.h"
#include "token.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TOKENS 10000

Token output[MAX_TOKENS];

const char OPERATORS[] = { '+', '-', '|', '$', '!', '%', '/', '*', '=', '<', '>', '^' };
/*
bool isOperator(char op) {
    for (int i = 0; i < 12; i++) {
        if (OPERATORS[i] == op) {
            return 1;
        } else {
            continue;
        }
    }
    return 0;
}
    */

Token *lex(char *input) {
    int index = 0;
    Token test = { "EOF", EOF_TOK, 0, 0, NULL };
    output[0] = test;
    return output;
}