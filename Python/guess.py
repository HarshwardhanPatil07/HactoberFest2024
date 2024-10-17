import random

def set_difficulty():
    print("\nChoose difficulty level:")
    print("1. Easy (10 attempts)")
    print("2. Medium (7 attempts)")
    print("3. Hard (5 attempts)")
    
    while True:
        choice = input("Enter your choice (1/2/3): ")
        if choice == '1':
            return 10
        elif choice == '2':
            return 7
        elif choice == '3':
            return 5
        else:
            print("Invalid choice. Please select 1, 2, or 3.")

def guess_the_number():
    print("Welcome to the Enhanced 'Guess the Number' game!")
    
    # Set difficulty level
    attempts_left = set_difficulty()
    
    # Random number between 1 and 100
    number_to_guess = random.randint(1, 100)
    
    attempts = 0
    guess = None
    
    while attempts_left > 0:
        try:
            # Get user's guess
            guess = int(input(f"\nEnter your guess (between 1 and 100): "))
            attempts += 1
            attempts_left -= 1
            
            # Check the guess and provide feedback
            if guess < number_to_guess:
                print("Too low!")
            elif guess > number_to_guess:
                print("Too high!")
            
            # Provide hints when close to the correct answer
            if abs(number_to_guess - guess) <= 5 and guess != number_to_guess:
                print("But you're very close!")
                
            # Win condition
            if guess == number_to_guess:
                print(f"🎉 Congratulations! You guessed the number {number_to_guess} in {attempts} attempts.")
                break
            
            # Out of attempts
            if attempts_left == 0:
                print(f"Game over! You've run out of attempts. The correct number was {number_to_guess}.")
                break
            else:
                print(f"Attempts left: {attempts_left}")
        
        except ValueError:
            print("Please enter a valid number.")

# Start the game
guess_the_number()
