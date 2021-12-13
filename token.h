#ifndef TOKEN_H
#define TOKEN_H

// > is it bad that I'm a femboy?! *uwu*
enum Tokens {
    // Special Characters in C
    Comma, LessThan, GreaterThan, Period, Underscore,
    LeftParen, RightParen, SemiColon, Dollar,
    Colon, Percent, LeftBracket, RightBracket,
    Hashtag,
    QuestionMark, SingleQuote, Ampersand, LeftCurlyBracket,
    RightCurlyBracket, DoubleQuote, ExponentiationMark,
    Bang, Star, Slash, UpwardsLine, Minus, Backslash,
    SquigglyLine, Plus,
    // Not C-standard special character, but a special character in Kawaii C nonetheless
    Equals,

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
   Typedef, Char, Extern,
   Return, Union,
   Continue, For, Do,
   If, Static, While,
   Default, Sizeof, Const,
   Inline,

   // Preprocessor
   Include, Define, Undef, Ifdef, Ifndef, IfPre, ElsePre, Elif, Endif, ErrorPre,

   // Std management
   Assemby,

   Newline, Endl,
}



#endif
