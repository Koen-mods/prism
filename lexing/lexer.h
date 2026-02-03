#ifndef LEXER_H
#define LEXER_H
#include "token.h"

bool isOperator(char op);

Token* lex();

#endif