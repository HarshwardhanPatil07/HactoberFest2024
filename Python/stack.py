#Write a menu driven program to implement Stack in Python using List
def isempty(stk):
    if stk==[]:
        return True
    else:
        return False

def push(stk,item):
    stk.append(item)
    top=len(stk)-1
    
def pop(stk):
    if isempty(stk):
        return 'Underflow'
    else:
        item=stk.pop()
        if len(stk)==0:
            top=None
        else:
            top=len(stk)-1
        return item    

def peek(stk):
    if isempty(stk):
        return "Underflow"
    else:
        top=len(stk)-1
        return(stk[top])

def display(stk):
    if isempty(stk):
        print("Stack is empty")
    else:
        for i in range(len(stk)-1,-1,-1):
            print(stk[i])

stk=[]
top=None
while True:
    print("Stack Operation:","\n1.Push","\n2.Pop","\n3.Peek","\n4.Display","\n5.Exit")
    ch=int(input("Enter your choice(1-5):"))
    if ch==1:
        item=int(input("Enter item"))
        push(stk,item)
    elif ch==2:
        item=pop(stk)
        if item=='Underflow':
            print("Stack is empty")
        else:
            print("popped item is",item)
    elif ch==3:
        item=peek(stk)
        if item=="Underflow":
            print("Stack is empty")
        else:
            print("Topmost item is ",item)
    elif ch==4:
        display(stk)
    elif ch==5:
        break
    else:
        print("Invalid Choice")
#Astha Kumari,12-E,roll-15    
        
    
    
