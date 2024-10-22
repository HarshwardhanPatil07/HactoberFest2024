# Function to check whether a number is prime or not
def is_prime(n):
    if n <= 1:
        return False

    # Check divisibility from 2 to n-1
    for i in range(2, n):
        if n % i == 0:
            return False

    return True

n = 11
print(is_prime(n))
