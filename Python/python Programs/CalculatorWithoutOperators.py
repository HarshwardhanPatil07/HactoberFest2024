# Program to create a simple calculator without using operators
def add(a, b):
    while b:
        carry = a & b
        a = a ^ b
        b = carry << 1
    return a

def subtract(a, b):
    while b:
        borrow = (~a) & b
        a = a ^ b
        b = borrow << 1
    return a

a = 10
b = 5
print("Addition:", add(a, b))
print("Subtraction:", subtract(a, b))
