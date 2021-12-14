#include "token.h"
#include <stdio.h>
#include <stdlib.h>

Scanner scanner;

void initScanner(const char *src) {
    scanner.start = src;
    scanner.current = src;
    scanner.line = 1;
};

static int isAtEnd() {
    return (*scanner.current == END);
};

static Tok createTok(TokType tok) {
    Tok token;
    token.type = tok;
    token.start = scanner.start;
    token.length = (int)(scanner.current-scanner.current);
    token.line = scanner.line;
    // Remove uninitialized data
    token.precision = -1;
    if (tok == Integer || tok == Float || tok == UnsignedInteger || tok == UnsignedFloat) {
        token.precision = getTokPre(token);
    };
    return token;
};

static char peek() {
    return *scanner.current;
};

static int isDigit(char c) {
    return (c >= '0' && c <= '9');
};

int getTokPre(Tok token) {
    char buf[5];
    int i = 0;
    while (isDigit(peek())) {
        if (i > 4) {
            genErrorTok("Types can only have max integer component of 4.");
        }
        buf[i] = peek();
        advance();
        i++;
    };
    // Make string null-terminated
    buf[4] = '\0';
    // Convert to int
    return atoi(token.start);
};

static Tok genErrorTok(const char* msg) {
    Tok token;
    token.type = Error;
    token.start = msg;
    token.length = (int)strlen(msg);
    token.precision = -1;
    return token;
};

Tok scanToken() {
    // Create starting bound (hover over current character)
    scanner.start = scanner.current;

    if (isAtEnd()) {
        return createTok(EndOfFile);
    }

    return genErrorTok("Unexpected character.");
};