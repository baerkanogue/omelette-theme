# omelette
import math

rate: float = 3.14             
rate_cos: float = math.cos(rate)
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
    print(i, "even" if i%2==0 else "odd")

try:
    1/0
except ZeroDivisionError:
    pass
finally:
    print("done")