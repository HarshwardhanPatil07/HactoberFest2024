class FactorialCalculator:
    def __init__(self, number):
        self.number = number

    def calculate(self):
        if self.number < 0:
            raise ValueError("Factorial is not defined for negative numbers.")
        return self._factorial(self.number)

    def _factorial(self, n):
        if n == 0 or n == 1:
            return 1
        else:
            return n * self._factorial(n - 1)

try:
    num = int(input("Enter a non-negative integer: "))
    calculator = FactorialCalculator(num)
    result = calculator.calculate()
    print(f"The factorial of {num} is {result}.")
except ValueError as e:
    print(e)
