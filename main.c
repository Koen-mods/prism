#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
    tokens = lex("({\n});", 7);

    for (int i = 0; i < 6; i++) {
        printf("%s\n", tokens[i].lexeme);
    }

    return 0;
}