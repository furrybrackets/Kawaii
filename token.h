#ifndef TOKEN_H
#define TOKEN_H

// > is it bad that I'm a femboy?! *uwu*
enum Tokens {
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
   Typedef, Char, Extern,
   Return, Union,
   Continue, For, Do,
   If, Static, While,
   Default, Sizeof, Const,

   // Preprocessor
   Include, Define, Undef, Ifdef, Ifndef, IfPre, ElsePre, Elif, Endif, ErrorPre,

   // Std management
   Assemby,

   Newline, Endl, Error,

   // Literals
   CharLiteral, IntLiteral, FloatLiteral, StringLiteral

   // Operators
   LogicalOr, LogicalAnd, LogicalNot, EqualEqual,
   NotEqual, GreaterThanOrEqualTo,
   LessThanOrEqualTo, 
   BitwiseAnd, BitwiseOr, BitwiseExclusiveOr,
   BitwiseComplement,
   ShiftLeft, ShiftRight,
   LogicalXor,
}


#endif