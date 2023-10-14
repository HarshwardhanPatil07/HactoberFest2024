# Username: Faheem219
# Aim: To create a programme that converts a decimal number to binary or octal number
# Date: 14/10/2023
import sys

def dec_to_bin_oct(num, base):
    if num < 0:
        num = -num
        sign = '-'
    else:
        sign = ''
    
    result_lst = []
    
    # Convert decimal to binary or octal
    while num >= 1:
        rem = num % base
        result_lst.append(rem)
        num //= base
    
    result_num = result_lst[::-1]
    
    return sign, result_num

# Main program
n = int(input("Enter the number corresponding to the operation:\n1. Decimal to Binary\n2. Decimal to Octal\n"))

if n == 1:
    base = 2
elif n == 2:
    base = 8
else:
    print("\nPlease enter a valid number")
    sys.exit()

num = int(input("\nEnter any decimal number:"))

if num == 0:
    print(f"\nThe {'binary' if base == 2 else 'octal'} form of 0 is: 0")
    sys.exit()

n1 = num
sign, result_num = dec_to_bin_oct(num, base)

print(f"\nThe {'binary' if base == 2 else 'octal'} form of {n1} is: {sign}", end="")

# Print the converted number
for i in result_num:
    print(i, end="")
