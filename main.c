#include <stdio.h>
#include <string.h>
#include "./lexing/token.h"
#include "./lexing/lexer.h"

#define VERSION "Prism, version 0.0.1\n"

int main(int argc, char *argv[]) {
    if (argc >= 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
                printf(VERSION);
                return 0;
            }
        }
    }

    Token *tokens;
    tokens = lex("test");

    printf("%s\n", tokens[0].lexeme);

    return 0;
}