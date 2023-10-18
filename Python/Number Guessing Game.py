import random
secret_number = random.randint(1, 100)
guesses = 0
max_guesses = 10
print("Welcome to the Number Guessing Game!")
print(f"I'm thinking of a number between 1 and 100. You have {max_guesses} guesses to find it.")
while guesses < max_guesses:
    try:
        guess = int(input("Enter your guess: "))
    except ValueError:
        print("Please enter a valid number.")
        continue
    guesses += 1
    if guess < secret_number:
        print("Too low. Try again.")
    elif guess > secret_number:
        print("Too high. Try again.")
    else:
        print(f"Congratulations! You've guessed the number {secret_number} in {guesses} guesses.")
        break
if guesses == max_guesses:
    print(f"Sorry, you've run out of guesses. The secret number was {secret_number}. Better luck next time!")