# Program to print 1 to 100 without using numbers
def print_numbers():
    for i in range(ord('A'), ord('A') + 26):
        print(chr(i), end=' ')
    print()
    
print("Printing numbers 1 to 100:")
print_numbers()
