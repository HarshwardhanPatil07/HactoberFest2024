board = [" "," "," ",
         " "," "," ",
         " "," "," ",]
def print_board():
    print("-------------")
    print("|",board[0],"|",board[1],"|",board[2],"|")
    print("-------------")
    print("|",board[3],"|",board[4],"|",board[5],"|")
    print("-------------")
    print("|",board[6],"|",board[7],"|",board[8],"|")
    print("-------------")

def check_winner(player):
    for i in range(3):
        if board[i]==board[i+3]==board[i+6]==player :
            return True
    for i in range(0,9,3):
        if board[i]==board[i+1]==board[i+2]==player :
            return True
    if board[0]==board[4]==board[8]==player :
            return True
    if board[2]==board[4]==board[5]==player :
            return True
    return False

def start_game():
     print("Welcome to TicTacToe")
     print_board()
     player="X"
     while True:
        n=int(input("player "+player+" can make a move (Enter the num between 1-9) :"))-1
        if board[n] == " ":
            board[n]=player
        else :
            print("Invalid move, try again!!")
            continue
        if check_winner(player) == True:
             print("Congratution player",player,"won the game!!")
             break
        if " " not in board:
             print("It is a tie!!")
             break
        if(player=="X"):
             player="O"
        else :
             player="X"
        print_board()
start_game()
        


