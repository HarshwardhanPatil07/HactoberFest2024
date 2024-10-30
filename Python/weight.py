

weight = int(input("Enter your Weight : "))
# print()
unit =input("(L)bs or (K)g: ")

if unit.lower()=='k':
    ans = weight/0.45
else:
    ans = weight*0.45

print(ans)

