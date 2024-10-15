# Program to calculate Fibonacci series using classes
class Fibonacci:
    def __init__(self, n):
        self.n = n

    def calculate(self):
        fib_series = [0, 1]
        for i in range(2, self.n):
            next_value = fib_series[-1] + fib_series[-2]
            fib_series.append(next_value)
        return fib_series[:self.n]

n = 10
fibonacci = Fibonacci(n)
print("Fibonacci series:", fibonacci.calculate())
