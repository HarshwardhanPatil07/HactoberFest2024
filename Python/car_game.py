
command  = ""
isStart,isStop=False,False
while True:
    command= input(">").lower()
    if command=="start":
        if isStart==False :
            print("Car started")
            isStart=True
        else:
            print("Car is already started")        
    elif command=="stop":
        if isStart==False:
            print("Car is not started yet")
        elif isStart==True and isStop==False:
            print("Car stopped")
            isStop=True
            isStart=False
        else:
            print("Car is already Stopped")
            isStop=False  
    elif command=="help":
        print("""start - to start the car
stop - to stop the car
quit - to quit
        """)
    elif command=='quit':
        print("Quit")
        break;
    else:
        print("I don't understand that")


