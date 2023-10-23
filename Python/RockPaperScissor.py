import random
def gamewin(comp,you):
    if comp== you:
        return None
    elif comp== 'rock':
        if you== 'paper':
            return True
        elif you=="scissor":
            return False
    elif comp== 'paper':
        if you== 'rock':
            return False
        elif you=="scissor":
            return True
    elif comp== 'scissor':
        if you== 'paper':
            return False
        elif you=="rock":
            return True
print("computer's turn!")             
randno=random.randint(1,3)
if randno==1:
    comp= "rock"
elif randno==2:
    comp= "paper"
elif randno==3:
    comp= "scissor"
you=input("your turn! = rock,paper,scissor ")
a= gamewin(comp,you)
print(f"computer chose {comp}")
print(f"you chose {you}")
if a== None:
    print("game is tie")
elif a:
    print("you win")
else:
    print("you lose")
