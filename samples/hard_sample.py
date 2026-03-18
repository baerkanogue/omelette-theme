# type: ignore
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Multiline docstring (should be string.quoted.docstring)
Includes "quotes", 'quotes', and escapes \n \t \\.
"""

import math as m
import sys
from collections import defaultdict as dd
from typing import List, Dict, Union, Optional, Callable

# --- Constants / numbers ---
INT = 123_456
FLOAT = 1.23e-4
HEX = 0xDEADBEEF
BIN = 0b1010_1010
OCT = 0o755
COMPLEX = 3 + 4j

# --- Unicode identifiers ---
π = 3.14159
变量 = "unicode_identifier"


# --- Decorators ---
def decorator(fn: Callable) -> Callable:
    def wrapper(*args, **kwargs):
        return fn(*args, **kwargs)

    return wrapper


@decorator
def func(a: int, b: int = 42, *args, **kwargs) -> int:
    """Function docstring"""
    global INT
    nonlocal_var = 10

    # --- Operators ---
    result = (a + b) * (a - b) / (a or b) and not False
    result **= 2
    result //= 3
    result %= 5
    result |= 1
    result &= 0xFF
    result ^= 0b1010
    result <<= 2
    result >>= 1

    # Walrus operator
    if (n := len(args)) > 0:
        print(f"{n=}")

    # --- Strings ---
    s1 = "double"
    s2 = "single"
    s3 = """triple double"""
    s4 = """triple single"""
    s5 = r"raw\nstring"
    s6 = f"formatted {a=} {b=}"
    s7 = rf"combo {a}\n"
    s8 = "escape \" ' \\ \n \t"

    # --- Collections ---
    lst = [i for i in range(10) if i % 2 == 0]
    st = {i for i in range(5)}
    dct = {k: v for k, v in zip(lst, st)}
    tpl = (1, 2, 3)

    # unpacking
    a1, *a2, a3 = lst
    merged = [*lst, *st]

    # slicing
    _slice = lst[1:5:2]

    # lambda
    lam = lambda x, y=2: x**y

    # --- Exception handling ---
    try:
        raise ValueError("error")
    except ValueError as e:
        print(e)
    except Exception:
        pass
    else:
        pass
    finally:
        pass

    # --- Context manager ---
    with open(__file__, "r") as f:
        data = f.read()

    # --- Pattern matching ---
    match a:
        case 0:
            pass
        case int(x) if x > 10:
            pass
        case _:
            pass

    return result


# --- Class with metaclass ---
class Meta(type):
    pass


class Base:
    def method(self):
        return super().method() if hasattr(super(), "method") else None


class MyClass(Base, metaclass=Meta):
    class_attr: int = 10

    def __init__(self, value: Union[int, float]) -> None:
        self.value = value

    @property
    def prop(self) -> int:
        return self.value

    @staticmethod
    def static():
        return None

    @classmethod
    def create(cls):
        return cls(0)

    def __str__(self):
        return f"MyClass({self.value})"

    def __add__(self, other):
        return MyClass(self.value + other.value)


# --- Async ---
async def async_func():
    async for i in agen():
        await m.sleep(0.1)
    return None


async def agen():
    for i in range(3):
        yield i


# --- Builtins / special names ---
__all__ = ["func", "MyClass"]
__version__ = "1.0.0"


# --- Boolean / None ---
flag = True if None is None else False


# --- Edge punctuation / weird constructs ---
expr = 1
trailing_comma = (1,)

# --- Main ---
if __name__ == "__main__":
    obj = MyClass(10)
    print(obj + MyClass(5))


# --------------------------------------------------
# NESTED F-STRINGS (deep + edge cases)
# --------------------------------------------------

x = 10
y = 3.14159

f1 = f"{f'{f'{x}'}'}"
f2 = f"{f'{x + f'{y}'}'}"
f3 = f"{f'{x:{f'{y:.2f}'}}'}"
f4 = f"{(lambda v: f'{v*2}')(x)}"
f5 = f"{f'{f'{f'{x=}'}'}'}"

# Conversion flags
f6 = f"{x!r} {x!s} {x!a}"

# Format spec nesting
f7 = f"{x:{10}.{2}}"
f8 = f"{x:{f'{5}'}.{f'{2}'}}"

# Escapes inside f-strings
f9 = f"escaped {{ braces }} and value {x}\n"

# Invalid / borderline (commented out intentionally)
# f_invalid_1 = f"{f'{x'"          # unclosed
# f_invalid_2 = f"{(1+2}"         # missing brace
# f_invalid_3 = f"{x!}"           # invalid conversion

# --------------------------------------------------
# STRINGS (rare prefixes and combinations)
# --------------------------------------------------

s1 = r"raw string \n \t \\"
s2 = "unicode string"
s3 = b"bytes string"
s4 = rf"raw formatted {x}\n"
s5 = rf"also valid {x}\n"

# Triple + nested quotes
s6 = """triple "double" 'single' """
s7 = """triple 'single' "double" """

# Edge escapes
s8 = "\x41 \u0041 \U00000041 \N{LATIN CAPITAL LETTER A}"

# --------------------------------------------------
# NUMERIC EDGE CASES
# --------------------------------------------------

n1 = 1_2_3_4_5
n2 = 0b_1010_1010
n3 = 0x_FF_FF
n4 = 1e10
n5 = 1e-10
n6 = 1j
n7 = 3.0 + 0.5

# --------------------------------------------------
# OPERATORS (rare / combined)
# --------------------------------------------------

a = 5
b = 2

op1 = a @ b  # matrix multiply
op2 = a**b**2  # precedence
op3 = (a := b)  # walrus
op4 = a if a is not None else b
op5 = a in [1, 2, 3] and b not in [4, 5]

# Bitwise chaining
op6 = a << 2 | b & 3 ^ 1

# --------------------------------------------------
# RARE KEYWORDS / STRUCTURES
# --------------------------------------------------


def generator():
    yield from range(3)


async def coro():
    await generator().__anext__()


# match-case edge usage
def matcher(value):
    match value:
        case 0 | 1:
            pass
        case [x, y]:
            pass
        case {"key": v}:
            pass
        case int() as i if i > 0:
            pass
        case _:
            pass


# --------------------------------------------------
# TYPE HINT EDGE CASES
# --------------------------------------------------

from typing import TypeVar, Generic, Callable

T = TypeVar("T", bound=int)


class GenericClass(Generic[T]):
    def method(self, fn: Callable[[T], T]) -> T:
        return fn(T())


# PEP 604 unions
def func(x: int | str | None) -> list[int | str]:
    return [x]


# --------------------------------------------------
# DECORATORS (stacked / complex)
# --------------------------------------------------


def deco1(f):
    return f


def deco2(arg):
    def wrap(f):
        return f

    return wrap


@deco1
@deco2(arg=42)
def decorated():
    pass


# --------------------------------------------------
# BUILTINS / MAGIC / EDGE IDENTIFIERS
# --------------------------------------------------

__magic__ = "__value__"
_ = 42
__ = 43

# unusual but valid identifiers
λ = lambda x: x + 1
变量 = 10

# --------------------------------------------------
# COMPREHENSIONS (nested + conditions)
# --------------------------------------------------

comp1 = [i * j for i in range(3) for j in range(3) if i != j]
comp2 = {i: j for i, j in zip(range(3), range(3))}
comp3 = (i for i in range(10) if i % 2)

# --------------------------------------------------
# ATTRIBUTE / CALL EDGE CASES
# --------------------------------------------------


class A:
    def __call__(self):
        return self

    def __getattr__(self, name):
        return name


a = A()
edge = a().foo.bar().baz

# --------------------------------------------------
# INVALID / FALLBACK GRAMMAR TESTS (COMMENTED)
# These often reveal "invalid" scopes in themes
# --------------------------------------------------

# def broken(: pass
# x = [1, 2, 3
# y = f"{1 + }"
# z = "unterminated string
# a = 1 + * 2

# --------------------------------------------------
# COMMENTS EDGE CASES
# --------------------------------------------------

# TODO: highlight TODO
# FIXME: highlight FIXME
# NOTE: highlight NOTE
# XXX: highlight XXX

# Shebang-like inside file
#! not actually a shebang here

# --------------------------------------------------
# END
# --------------------------------------------------
