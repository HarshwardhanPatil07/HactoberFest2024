first = int(input("Enter first number = "))
second = int(input("Enter second number = "))
operator = input("Enter operator (+,-,/,*) : ")

if operator =='+':
    print(first+second)
elif operator =='-':
    print(first-second)
elif operator =='*':
    print(first*second)
elif operator =='/':
    print(first//second)
else:
    print("Not a valid operator")