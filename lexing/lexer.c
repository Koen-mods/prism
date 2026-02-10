#include "lexer.h"
#include "token.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TOKENS 10000

Token output[MAX_TOKENS];

const char OPERATORS[] = { '+', '-', '|', '$', '!', '%', '/', '*', '=', '<', '>', '^' };

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

Token *lex(char *input, int length) {
    int index = 0;
    int line = 0;

    for (int i = 0; i < length; i++) {
        if (input[i] == '(') {
            Token tok = { "(", LPAREN, index, line, NULL };
            output[index] = tok;
            index++;
            continue;
        }
    }

    Token EOF_TOKEN = {"EOF", EOF_TOK, index, line, NULL };
    output[index] = EOF_TOKEN;
    return output;
}