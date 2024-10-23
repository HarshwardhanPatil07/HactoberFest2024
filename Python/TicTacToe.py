board = [" "," "," ",
         " "," "," ",
         " "," "," ",]         # the "=" assignment operator assigns the board design to the variable "board" 
def print_board():     # defines the function print_board - uses the defined variable "board" to create the board
    print("-------------")
    print("|",board[0],"|",board[1],"|",board[2],"|") 
    print("-------------")
    print("|",board[3],"|",board[4],"|",board[5],"|")
    print("-------------")
    print("|",board[6],"|",board[7],"|",board[8],"|")
    print("-------------")

def check_winner(player):
    for i in range(3): # checking to see if the vertical column has equal values - vertical win 
        if board[i]==board[i+3]==board[i+6]==player :
            return True
    for i in range(0,9,3): # checking to see if the horizontal column has equal values - horizontal win 
        if board[i]==board[i+1]==board[i+2]==player :
            return True
    if board[0]==board[4]==board[8]==player : # checking for diagonal win from top left to bottom right 
            return True
    if board[2]==board[4]==board[6]==player : # checking for diagnoal win from top right top bottom left
            return True
    return False

def start_game():
     print("Welcome to TicTacToe") # welcome message 
     print_board() # prints the initial blank board 
     player="X"
     while True: # continues game until there is a winner/tie
        n=int(input("player "+player+" can make a move (Enter the num between 1-9) :"))-1 # asking player where they want to mark the grid 
        if board[n] == " ": # allows player to make move if that spot is blank 
            board[n]=player
        else :
            print("Invalid move, try again!!") # won't let player make move if spot is taken 
            continue
        if check_winner(player) == True: # uses the defined function "check_winner" to check if player has won 
             print("Congratution player",player,"won the game!!")
             break
        if " " not in board: # no empty spaces left, so it's a tie 
             print("It is a tie!!")
             break
        if(player=="X"): # switches from player X to player O
             player="O"
        else :
             player="X"
        print_board() # updates board after each move 
start_game() # calls the start_game function to start the game 
        


