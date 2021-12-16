#ifndef TOKEN_H
#define TOKEN_H

#ifndef END
    #define END '\0'
#endif

#include <stdio.h>
#include <string.h>

// > is it bad that I'm a femboy?! *uwu*
typedef enum Tokens {
    // Special Characters in C
    Comma, LessThan, GreaterThan, Period, Underscore,
    LeftParen, RightParen, SemiColon, Dollar,
    Colon, Modulo, LeftBracket, RightBracket,
    Hashtag,
    QuestionMark, SingleQuote, LeftCurlyBracket,
    RightCurlyBracket, DoubleQuote,
    Bang, Star, Slash, Minus, EscapeSlash, Plus,
    // Not C-standard special character, but a special character in Kawaii C nonetheless
    Equal,

    // Types (LLVM-IR style)
    
    /// Integer type
    Integer, UnsignedInteger,

    /// Floating Point Type
    Float, UnsignedFloat,

    /// Character Types
    Char, LongChar,

    /// Logical Types
    Bool, /* Alias for i1 */

    /// Void Type
    Void,

    // Keywords

   Struct, Break, Else,
   Switch, Case, Enum,
   Typedef, Extern,
   Return, Union,
   Continue, For, Do,
   If, Static, While,
   Default, Sizeof, Const,

   // Preprocessor
   Include, Define, Undef, Ifdef, Ifndef, IfPre, ElsePre, Elif, Endif, ErrorPre,

   // Std management
   Assemby,

   Newline, EndOfFile, Error,

   // Literals
   CharLiteral, IntLiteral, FloatLiteral, StringLiteral,

   // Operators
   LogicalOr, LogicalAnd, LogicalNot, EqualEqual,
   NotEqual, GreaterThanOrEqualTo,
   LessThanOrEqualTo, 
   BitwiseAnd, BitwiseOr, BitwiseExclusiveOr,
   BitwiseComplement,
   ShiftLeft, ShiftRight,
   LogicalXor,
} TokType;

typedef struct {
    const char *start;
    const char *current;
    int line;
} Scanner;

typedef struct {
    TokType type;
    const char* start;
    int length;
    int line;
    int precision; // <- Used for LLVM-types (i1, i2, i4, i8, i32, f64, etc), if not a type, precision is 0.
} Tok;

static Tok genErrorTok(const char* msg);

static Tok createTok(TokType tok);

static int isAtEnd();

Tok scanToken();

void initScanner(const char* src);



/* 
This could might confuse some people (understandably), so I'll explain to the best of my ability:

Let's say we have a string like this:

hello my friend

There are two different pointers. We start them both off at 0:

hello darkness my old friend
^ <- Hovering character
$ <- Consumed character

The consumed character is the one we can read, while the hovering character is the one we *will* read when it is time.

Normally, at any point, the two positions should move something like this:

Consume start[0]:

hello darkness my old friend
 ^
$ 

Current character being read: h

Finish with char[0], advance:

hello darkness my old friend
  ^
 $

Current character being read: e

When we match, we are checking the character in the future, and then changing the current position to that character after checking, for example:

data: $=
      * <- cur char being read: $

[match('=') ? MoneyEq : Money] means:

data: $=
       ^ <- Check the pointed character

then,

$=
 * <- Make the current character the checked character

data

*/
static int match(char expected);

// Does what you'd expect, *uwu*
static char advance();

static void skipWhite();

// Doesn't consume the character
static char peek();

static char peekNext(const int howMany);


// Pass function, will be called by the `compile` function during compile time.
void scanDoc(const char *src);

int getTokPre(Tok token);


static int isDigit(char c);

#endif