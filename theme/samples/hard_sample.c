// -*- mode: c; -*-

/**************************************************
 * MULTILINE COMMENT (block)
 * Includes symbols: {} [] () ; , * & #
 **************************************************/

#include <stdio.h>
#include <stdlib.h>

#define CONST_INT 123
#define CONST_HEX 0xDEADBEEF
#define CONST_BIN 0b10101010   // (non-standard but often highlighted)
#define CONST_OCT 0777

// Function-like macros
#define SQUARE(x) ((x) * (x))
#define VARIADIC(fmt, ...) printf(fmt, __VA_ARGS__)

// Stringification and token pasting
#define STR(x) #x
#define CONCAT(a, b) a##b

// Nested macros
#define NESTED(x) SQUARE(SQUARE(x))

// --------------------------------------------------
// TYPES / QUALIFIERS / STORAGE
// --------------------------------------------------

typedef unsigned long long ull;

static const volatile int global_var = 42;

extern int external_var;

// --------------------------------------------------
// STRUCT / UNION / ENUM
// --------------------------------------------------

struct Point {
    int x;
    int y;
};

union Data {
    int i;
    float f;
    char str[20];
};

enum Color {
    RED = 1,
    GREEN,
    BLUE = 10,
};

// Anonymous struct / union (edge case)
struct {
    int a;
    union {
        int b;
        float c;
    };
} anon;

// --------------------------------------------------
// FUNCTION POINTERS
// --------------------------------------------------

int add(int a, int b) { return a + b; }

int (*func_ptr)(int, int) = &add;

// pointer to function returning pointer
int *(*complex_fp)(int);

// --------------------------------------------------
// ATTRIBUTES (GCC / Clang)
// --------------------------------------------------

__attribute__((unused))
static void attr_func(void) {}

__attribute__((aligned(16))) int aligned_var;

// --------------------------------------------------
// STRINGS / CHAR / ESCAPES
// --------------------------------------------------

char c1 = 'a';
char c2 = '\n';
char c3 = '\x41';
char c4 = '\101';  // octal

const char *s1 = "normal string";
const char *s2 = "escaped \" \\ \n \t";
const char *s3 = "multi" "part" "string"; // concatenation

// --------------------------------------------------
// NUMERIC EDGE CASES
// --------------------------------------------------

int n1 = 1'000'000; // C23 digit separator (may fallback)
double n2 = 1e+10;
double n3 = 1e-10;
double n4 = .5;
double n5 = 3.;
float n6 = 1.0f;
long double n7 = 1.0L;

// --------------------------------------------------
// ARRAYS / POINTERS / COMPLEX DECLARATIONS
// --------------------------------------------------

int arr[10];
int *ptr = arr;
int (*ptr_to_arr)[10];

int multi[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

// pointer arithmetic
int val = *(ptr + 1);

// --------------------------------------------------
// CONTROL FLOW
// --------------------------------------------------

void control(int x) {
    if (x > 0) {
        x++;
    } else if (x < 0) {
        x--;
    } else {
        x = 0;
    }

    for (int i = 0; i < 10; i++) {
        continue;
    }

    while (x--) {
        break;
    }

    do {
        x++;
    } while (x < 5);

    switch (x) {
        case 0:
            break;
        case 1:
        case 2:
            break;
        default:
            break;
    }

    goto label;

label:
    return;
}

// --------------------------------------------------
// BITWISE / OPERATORS
// --------------------------------------------------

void ops(void) {
    int a = 5, b = 3;

    a += b;
    a -= b;
    a *= b;
    a /= b;
    a %= b;

    a <<= 1;
    a >>= 1;

    a &= b;
    a |= b;
    a ^= b;

    int c = (a > b) ? a : b;
}

// --------------------------------------------------
// PREPROCESSOR EDGE CASES
// --------------------------------------------------

#if defined(CONST_INT) && !defined(UNKNOWN)
#   define CONDITIONAL 1
#elif defined(OTHER)
#   define CONDITIONAL 2
#else
#   define CONDITIONAL 0
#endif

#ifdef __GNUC__
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#line 100 "fake_file.c"

// --------------------------------------------------
// VARIADIC FUNCTIONS
// --------------------------------------------------

#include <stdarg.h>

void variadic(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int v = va_arg(args, int);
    }
    va_end(args);
}

// --------------------------------------------------
// INVALID / FALLBACK GRAMMAR TESTS (COMMENTED)
// --------------------------------------------------

// int broken = ;                  // missing value
// char *s = "unterminated string
// int x = (1 + 2;                 // missing parenthesis
// #define BAD_MACRO(x x           // malformed macro
// int y = 1 + * 2;                // invalid operator sequence

// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main(void) {
    struct Point p = { .x = 1, .y = 2 }; // designated initializer
    printf("Point: %d %d\n", p.x, p.y);

    VARIADIC("Value: %d\n", CONST_INT);

    int concat_test = CONCAT(12, 34);

    return 0;
}