// -*- mode: c++; -*-

/**************************************************
 * COMMENTS (block + edge content)
 **************************************************/

#include <iostream>
#include <vector>
#include <type_traits>
#include <initializer_list>

// --------------------------------------------------
// MACROS / PREPROCESSOR
// --------------------------------------------------

#define STR(x) #x
#define CONCAT(a,b) a##b
#define VARIADIC(fmt, ...) printf(fmt, __VA_ARGS__)

#if defined(__cplusplus) && __cplusplus >= 202002L
#   define CPP20 1
#else
#   define CPP20 0
#endif

// --------------------------------------------------
// TYPES / TYPEDEFS / USING
// --------------------------------------------------

typedef unsigned long long ull;
using ll = long long;

using func_t = int(*)(int, int);

// --------------------------------------------------
// ENUMS
// --------------------------------------------------

enum OldEnum { A, B, C };

enum class StrongEnum : int {
    X = 1,
    Y,
    Z = 10
};

// --------------------------------------------------
// STRUCT / CLASS / UNION
// --------------------------------------------------

struct Base {
    virtual ~Base() = default;
    virtual void foo() const = 0;
};

class Derived final : public Base {
public:
    int value{0};

    Derived() = default;
    explicit Derived(int v) noexcept : value(v) {}

    void foo() const override {
        std::cout << "Derived\n";
    }
};

union Data {
    int i;
    float f;
};

// --------------------------------------------------
// TEMPLATES (ADVANCED)
// --------------------------------------------------

template<typename T>
concept Integral = std::is_integral_v<T>;

template<typename T>
requires Integral<T>
T add(T a, T b) {
    return a + b;
}

// Template specialization
template<>
int add<int>(int a, int b) {
    return a + b + 1;
}

// Variadic templates
template<typename... Args>
void print_all(Args&&... args) {
    (std::cout << ... << args) << '\n'; // fold expression
}

// Template template parameter
template<template<typename> class Container, typename T>
struct Wrapper {
    Container<T> data;
};

// --------------------------------------------------
// AUTO / DECLTYPE / TYPE DEDUCTION
// --------------------------------------------------

auto func_auto(int x) -> decltype(x * 2) {
    return x * 2;
}

decltype(auto) perfect_forward() {
    static int x = 42;
    return (x);
}

// --------------------------------------------------
// LAMBDAS (EDGE CASES)
// --------------------------------------------------

auto lambda = [](int a, int b) -> int {
    return a + b;
};

auto complex_lambda = [x = 42](auto&&... args) mutable noexcept -> int {
    return ((args + ...) + x);
};

// generic lambda
auto generic = [](auto x) { return x * 2; };

// --------------------------------------------------
// OPERATORS
// --------------------------------------------------

struct Vec {
    int x, y;

    Vec operator+(const Vec& other) const {
        return {x + other.x, y + other.y};
    }

    Vec& operator+=(const Vec& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator==(const Vec&) const = default;
};

// spaceship operator (C++20)
struct Ord {
    int v;
    auto operator<=>(const Ord&) const = default;
};

// --------------------------------------------------
// LITERALS
// --------------------------------------------------

auto i1 = 123;
auto i2 = 0xFF;
auto i3 = 0b1010;
auto i4 = 1'000'000;

auto f1 = 1.0;
auto f2 = 1e-10;
auto f3 = 3.;
auto f4 = .5;

auto c1 = 'a';
auto c2 = '\n';

auto s1 = "string";
auto s2 = R"(raw string \n "quotes")";
auto s3 = u8"utf8";
auto s4 = L"wide";
auto s5 = u"utf16";
auto s6 = U"utf32";

// user-defined literal
long double operator"" _km(long double x) {
    return x * 1000;
}

auto dist = 10.0_km;

// --------------------------------------------------
// POINTERS / REFERENCES
// --------------------------------------------------

int x = 10;
int& ref = x;
int&& rref = 20;

int* ptr = &x;
int** pptr = &ptr;

// --------------------------------------------------
// SMART POINTERS
// --------------------------------------------------

#include <memory>

auto uptr = std::make_unique<int>(42);
auto sptr = std::make_shared<int>(42);

// --------------------------------------------------
// EXCEPTIONS
// --------------------------------------------------

void may_throw() {
    throw std::runtime_error("error");
}

void test_ex() {
    try {
        may_throw();
    } catch (const std::exception& e) {
        std::cerr << e.what();
    } catch (...) {
    }
}

// --------------------------------------------------
// RTTI / CASTS
// --------------------------------------------------

void casts(Base* b) {
    dynamic_cast<Derived*>(b);
    static_cast<Derived*>(b);
    const_cast<Derived*>(b);
    reinterpret_cast<long>(b);
}

// --------------------------------------------------
// ATTRIBUTES
// --------------------------------------------------

[[nodiscard]] int important() { return 42; }

[[deprecated("use something else")]]
void old_func() {}

[[maybe_unused]] int unused_var;

// --------------------------------------------------
// INITIALIZATION EDGE CASES
// --------------------------------------------------

std::vector<int> v{1,2,3};
int arr[] = {1,2,3};

Derived d{42};

// designated initializer (C++20)
struct S { int a; int b; };
S s = {.a = 1, .b = 2};

// --------------------------------------------------
// CONTROL FLOW
// --------------------------------------------------

void control(int n) {
    if (n > 0) {}
    else if (n < 0) {}
    else {}

    for (int i = 0; i < 10; ++i) {}

    while (n--) {}

    do {} while (n < 5);

    switch (n) {
        case 1: break;
        default: break;
    }
}

// --------------------------------------------------
// NAMESPACES
// --------------------------------------------------

namespace ns1::ns2 {
    int value = 10;
}

// --------------------------------------------------
// INVALID / FALLBACK (COMMENTED)
// --------------------------------------------------

// template<typename T
// auto x = std::vector<>>();
// int y = 1 + * 2;
// std::string s = "unterminated
// auto bad = []( { return 0; };

// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main() {
    Derived d(5);
    d.foo();

    print_all(1, " test ", 3.14);

    Vec a{1,2}, b{3,4};
    auto c = a + b;

    std::cout << c.x << "," << c.y << "\n";

    return 0;
}