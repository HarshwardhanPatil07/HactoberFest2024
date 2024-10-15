# Program to calculate factorial using classes
class Factorial:
    def __init__(self, n):
        self.n = n

    def calculate(self):
        if self.n == 0:
            return 1
        result = 1
        for i in range(1, self.n + 1):
            result *= i
        return result

n = 5
factorial = Factorial(n)
print("Factorial of", n, "is:", factorial.calculate())
