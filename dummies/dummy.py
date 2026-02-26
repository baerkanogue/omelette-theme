# omelette
import math

x = 42               
y = 3.14             
name = "Alice"       
flag = True          
nothing = None       

def greet(who: str) -> str:
    return f"Hello {who}"

class Person:
    species = "Human"
    def __init__(self, name):
        self.name = name
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