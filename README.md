# Kawaii C

The cutest, bestest C-like programming language!

## OwO? What is this?

Kawaii is a super-minimal, LLVM-oriented language, similar to C. It provides the following:

* Improved tooling (i.e. built in package manager and build system)
* Better macro system
* Improved syntax
* Almost 100% backwards compatibility
* Fast
* C-ABI
* Small
* *and more*

## Syntax Demo

```kawaii
// comment

/* 
multiple
lines
*/

// variable declarations
const x: i32 = 10;
let   y: i32 = 10;

// functions
fn f(x: i32, y: i32): [i32, i32] {
  return [x,y];
};

// structs, oh and unicode
struct θ {
    x: i32;
    y: i32;
};

// no OOP bullshit, just minor adaptions
impl θ {
  fn op+(self: *θ, other: θ) {
    return struct θ { x: (self->x+other.x), y: (self->y+other.y) };
  }
}

// Use operator overloading
const P: θ = struct θ {
  x: 1,
  y: 2
};

// implict typing
const Q = P;

// io
import { printf } from "c/stdio"; // omit the .h
import { fmt } from "fmt";

printf(fmt("Q+P: {}", Q+P));
```
