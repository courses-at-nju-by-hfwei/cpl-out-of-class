# `static`

- local variable (defined in some function)
  - scope: block scope
  - storage duration/lifetime: automatic
  - stack (stack frame for its enclosing function)
- global variable (defined out of any functions)
  - scope: file scope
  - storage duration/lifetime: static
  - at the beginning of the execution of the program till the end of the execution
- static local variable
  - `uid`
    - using local variable (debug; visualization)
    - using global variable
    - using static local variable (debug; visualization)
  - `rand`
  - `fib`
    - counting function calls
    - memo
- static global variable