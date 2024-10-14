import operator

def calculator(num1, num2, operation):
    if operation == 'add':
        return operator.add(num1, num2)
    elif operation == 'subtract':
        return operator.sub(num1, num2)
    elif operation == 'multiply':
        return operator.mul(num1, num2)
    elif operation == 'divide':
        return operator.truediv(num1, num2)
    else:
        return "Invalid operation"

# Example usage
num1 = int(input("Enter first number: "))
num2 = int(input("Enter second number: "))
operation = input("Choose operation (add, subtract, multiply, divide): ")

result = calculator(num1, num2, operation)
print(f"Result: {result}")
