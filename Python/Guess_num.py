secret_num = 10

guess_count =0
guess_limit =5

while guess_count<guess_limit:
    guess_count+=1
    guess = int(input("Guess : "))
    if(guess==secret_num):
        print("You Won")
        break
else:
    print("Sorry, You failed")
