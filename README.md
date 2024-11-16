![image](https://github.com/user-attachments/assets/ba72237e-b5eb-42ae-96a3-8be4e92db8f4)

# c'est la vie
*C Unit Testing Framework*

Welcome to **c'est la vie** (abbreviated as `CLV`), a unit testing framework for C.

This framework is made to emphasize the importance of unit testing to beginner programmers who are using C. I personally believe learning how to perform *test-driven* development is an invaluable skill as a programmer, and hence this framework was created.

This framework adopts a *plug-and-play* mindset when it comes to testing, believing that it should not require a lot of effort to begin writing tests. CLV aims to kickstart the testing process, so that you can immediately get back to producing more and *safer* code.

> DISCLAIMER: This framework can really only be useful if you have written your C code in a *modular* way. This means your functions to be tested should be decoupled from your file that contains the `main` function of your binary.

## Installation & Dependencies

1. First, ensure that the following dependencies are satisfied:
    - A C compiler (`gcc`, `clang`)
    - `git`
    - `make`
2. Clone this repository.
```bash
git clone https://github.com/44mira/clv
cd clv
```
3. (OPTIONAL) Build `clv` from source.
```bash
go build clv.go     # requires go
```
4. (OPTIONAL) Add the `clv` binary to your system `PATH`.
```bash
make tests
```

## Usage

1. Run `clv init` (or the path to the `clv` binary) in your project's root folder. This should create a directory named `tests/` containing the library files for CLV.

> NOTE: `clv init` **will** overwrite directories.

2. Create test files in this directory for your usecase. These files should end in a `_test.c` or `_test.cpp` suffix.
    - Alternatively, you can use `clv create <test_name> [... <test_name>]` to create a test from a base template.
        - Brackets in this notation signify that `clv create` can create multiple test files with the same command.
    - Missing this step will cause an error in building the tests.
3. You can now write your tests!
4. To run your tests, first compile them with `make tests` and then simply run the `test` binary found in your project root folder.
> NOTE: `make tests` will temporarily create a `build` directory and then clean it up afterwards, removing it. This will overwrite any existing directory named `build`! If you do not want this behavior, you can edit it in the Makefile.

Example:
```c
#include "clv.h"
#include <stdio.h>
#include "../my_code.h"                 /* decoupled business functions */

int main() {
    SETUP;                              /* CLV requires that you add a SETUP and TEARDOWN at the end and beginning
                                           of your program lifetime. */

    ASSERT((5 == 5));                   /* Pass a condition to `ASSERT` and it will document the test result. */
    ASSERT_TRUE((5 == 5));              /* ASSERT can also be called as `ASSERT_TRUE` if you prefer a more explicit naming scheme. */

    TEST_LABEL("4 is not equal to 5");  /* You can attach an optional test label to your tests by calling this macro before the assert! */
    ASSERT_FALSE((4 != 5));             /* You can also use `ASSERT_FALSE` if you prefer it over ASSERT((!condition)) */

    TEST_LABEL("4 is an odd number");
    ASSERT(myIsOdd(4));                 

    TEARDOWN;
}
```

Output:
```
  OK   | TEST #01 LINE 8    
  OK   | TEST #02 LINE 10   
 FAIL  | TEST #03 LINE 16    | 4 is not equal to 5
 FAIL  | TEST #04 LINE 20    | 4 is an odd number
```

## API Reference

Check out the [wiki!](https://github.com/44mira/clv/wiki/API-Reference)
