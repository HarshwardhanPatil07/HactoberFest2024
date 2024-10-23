class FactorialCalculator:
    def __init__(self, number):
        self.number = number

    def calculate_factorial(self):
        if self.number < 0:
            return "Factorial is not defined for negative numbers."
        elif self.number == 0 or self.number == 1:
            return 1
        else:
            result = 1
            for i in range(2, self.number + 1):
                result *= i
            return result

# Example usage:
if __name__ == "__main__":
    num = 6
    factorial_calculator = FactorialCalculator(num)
    result = factorial_calculator.calculate_factorial()
    print(f"The factorial of {num} is: {result}")
