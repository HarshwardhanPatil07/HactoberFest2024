#  Github username : msabhii
#  Aim : Added the Python folder and a simple program too
# Date : 10-10-2023

for i in range(4):
    for i in range(4):
        print("# ", end="")

    print()

print("Using Pattern 1")

print("")

# printing in pattern

for i in range(4):
    for j in range(i + 1):
        print("# ", end="")

    print()


print("Using Pattern 2")

# printing in pattern

for i in range(4):
    for j in range(4 - i):
        print("# ", end="")

    print()
