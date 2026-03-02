# omelette
import math
from time import sleep

rate: float = 3.14
name: str = "Alice"
flag: bool = True


def greet(who: str) -> str:
    return f"Hello {who}"


class Person:
    species = "Human"

    def __init__(self, name: str):
        self.name: str = name
        self.age: int = 32

    def hello(self):
        print(greet(self.name))


for i in range(2):
    print(i, "even" if i % 2 == 0 else "odd")

try:
    while True:
        x = 1 / 0
except ZeroDivisionError as error:
    print(f"ERROR: {error}")
