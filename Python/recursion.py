# Program to print factorial of a number
# recursively.
#Pawan8576
#13/10/2023



# Recursive function
def recursive_factorial(n):
if n == 1:
	return n
else:
	return n * recursive_factorial(n-1)

# user input
num = 6

# check if the input is valid or not
if num < 0:
print("Invalid input ! Please enter a positive number.")
elif num == 0:
print("Factorial of number 0 is 1")
else:
print("Factorial of number", num, "=", recursive_factorial(num))
