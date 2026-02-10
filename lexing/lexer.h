#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <stdbool.h>

bool isOperator(char op);

Token* lex(char *input, int length);

#endif