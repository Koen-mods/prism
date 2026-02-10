#include "lexer.h"
#include "token.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
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

char *subString(char *input, int start, int end) {
    char *output;
    void *space = malloc((end - start) + 1);
    int pos = 0;
    for (int i = start; i < end; i++) {
        *(output + pos) = *(input + i);
        pos++;
    }
    output[(end - start) + 1] = '\0';
    strcpy((char *)space, output);
    return space;
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
        } else if (input[i] == ')') {
            Token tok = { ")", RPAREN, index, line, NULL };
            output[index] = tok;
            index++;
            continue;
        } else if (input[i] == '{') {
            Token tok = { "{", LBRACE, index, line, NULL };
            output[index] = tok;
            index++;
            continue;
        } else if (input[i] == '}') {
            Token tok = { "}", RBRACE, index, line, NULL };
            output[index] = tok;
            index++;
            continue;
        } else if (isdigit(input[i])) {
            int begin = i;
            int end = length;
            for (int j = 0; j < end; j++) {
                if (!isdigit(input[i]) && input[i] != '.') {
                    end = j;
                    i = j - 1;
                    break;
                } else {
                    continue;
                }
            }
            char *number = subString(input, begin, end);
            float literal = atof(number);
            void *literalMem = &literal;
            Token tok = { number, FLOAT, index, line, literalMem };
            output[index] = tok;
            index++;
        } else if (input[i] == '\n') {
            Token tok = { "\\n", NEWLINE, index, line, NULL };
            line++;
            output[index] = tok;
            index++;
        } else if (isOperator(input[i])) {
            char *op;
            op[0] = input[i];
            op[1] = '\0';
            Token tok = { op, OPERATOR, index, line, NULL };
            output[index] = tok;
            index++;
        }
    }

    Token EOF_TOKEN = {"EOF", EOF_TOK, index, line, NULL };
    output[index] = EOF_TOKEN;
    return output;
}