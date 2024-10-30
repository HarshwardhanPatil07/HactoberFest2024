/*
Date : 14.02.2022
Place : Chennai, Tamil Nadu, India
JERIN B S

||||||||||||||||||||TIC - TAC - TOE||||||||||||||||||||||||||||||||||
OUTLINE:

The game comes in a 3x3 grid.
Each position of grid is addressed by numbers from 1 to 9.

1 | 2 | 3
4 | 5 | 6
7 | 8 | 9

Always the user is given the first move.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

char space[] = {'\0','-','-','-','-','-','-','-','-','-'};//initialize table
char user = '\0', sys;//set user and sytem variable for 'X' and 'O'
int i, dummy, input, s_r;//s_r --> system random
bool flag = 0;
int state = 0;

void print_table(char table[]);

void check_win(char table[]);
char winner = '\0';

int randomx(int lower, int upper, int count);//to generate random numbers.
int num;

int check_draw(char table[]);

int main(){
    srand(time(0));//seed random with time.

    //SETTING USER AND SYSTEM SYMBOLS////////////////////////////////////////////////////////
    printf("Choose your symbol [X/O] : ");
    do{
        scanf("%d", &dummy);//no use.
        scanf("%c", &user);
        if((user == 'X') || (user == 'O')){
            flag = 1;
        }
        else{
            flag = 0;
            printf("Please enter a valid symbol [X/O] (case sensitive) : ");
        }
    }while(flag == 0);
    flag = 0;
    system("cls");
    if(user == 'X'){
        sys = 'O';
    }
    else{
        sys = 'X';
    }
    /////////////////////////////////////////////////////////////////////////////////////////

    print_table(space);

    
    while(winner == '\0'){

        //GETTING INPUT FROM USER////////////////////////////////////////////////////////////
        do{
            printf("\nMake your move : ");
            //scanf("%d", &dummy);
            scanf("%d", &input);

            if(space[input] == '-'){
                space[input] = user;
                flag = 1;
            }
            else{
                printf("Please enter a valid move");
                flag = 0;
            }
        }while(flag == 0);
        flag = 0;
        /////////////////////////////////////////////////////////////////////////////////////

        //CHECK IF THE GAME PLAY ENDED///////////////////////////////////////////////////////
        state = check_draw(space);
        if(state == 1){
            system("cls");
            print_table(space);
            printf("\nDraw");
            exit(0);
        }
        else if(state == 2){
            system("cls");
            print_table(space);
            if(winner == user){
                printf("\nYou Win!");
                exit(0);
            }
            else{
                system("cls");
                print_table(space);
                printf("\nYou Loose.");
            }
        }
        else{};
        system("cls");
        //////////////////////////////////////////////////////////////////////////////////////////

        //COMPUTER'S TURN////////////////////////////////////////////////////////////////////////
        s_r = randomx(1, 9, 1);
        do{
            if(space[s_r] == '-'){
                space[s_r] = sys;
                flag = 1;
            }
            else{
                s_r = randomx(1, 9, 1);
                flag = 0;
            }
        }while(flag == 0);
        ///////////////////////////////////////////////////////////////////////////////////////////

        print_table(space);
        check_win(space);
        //printf("%c", winner);
    }
    //CHECK WHO WON///////////////////////////////////////////////////////////////////////////////
    if(winner == user){
        printf("\nYou Win!");
    }
    else{
        system("cls");
        print_table(space);
        printf("\nYou Loose.");
    }  
    //////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}

void print_table(char table[]){
    for(i = 1; i < 10; i++){
        printf(" %c ", table[i]);
        if((i != 3) && (i != 6) && (i != 9)){
            printf("|");
        };
        if((i == 3) || (i == 6)){
            printf("\n");
        }
    }
}

void check_win(char table[]){
    //horizontal check.
    for(i = 1; i <= 7; i+=3){
        if((table[i] == table[i + 1]) && (table[i] == table[i + 2]) && (table[i] != '-')){
            winner = table[i];
            return;
        }
        else{};
    }

    //vertical check.
    for(i = 1; i <= 3; i++){
        if((table[i] == table[i + 3]) && (table[i] == table[i + 6]) && (table[i] != '-')){
            winner = table[i];
            return;
        }
        else{};
    }

    //right diagonal check.
    if((table[1] == table[5]) && (table[1] == table[9]) && (table[1] != '-')){
        winner = table[5];
        return;
    }
    //left diagonal check.
    else if((table[3] == table[5]) && (table[3] == table[7]) && (table[3] != '-')){
        winner = table[5];
        return;
    }
    else{};
    return;
}

int randomx(int lower, int upper, int count){
    for (i = 0; i < count; i++) {
        num = (rand() % (upper - lower + 1)) + lower;
        return num;
    }
}

int check_draw(char table[]){
    int j = 0;
    check_win(space);
    if(winner == '\0'){
        for(i = 1; i < 10; i++){
            if(table[i] == '-'){
                return 0;
                break;
            }
            else{
                continue;
            }
        }
        for(i = 1; i < 10; i++){
            if(table[i] != '-'){
                j++;
            }
            else{};
        }
        if(j == 9){
            return 1;
        }
        else{};
    }
    else{
        return 2;
    }
}