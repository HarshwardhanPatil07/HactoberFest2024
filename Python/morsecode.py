# Name of Contributer -- Sujit Nirmal 
# Date of contribution -- Mon 14, 2024
# github username -- @blacksujit
# aim -- A dictionary MORSE_CODE_DICT is used to map characters to their Morse code equivalent and vice versa. to show this implementation i have added the code 

# Morse Code Dictionary
MORSE_CODE_DICT = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 
    'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 
    'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 
    'Y': '-.--', 'Z': '--..', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', 
    '6': '-....', '7': '--...', '8': '---..', '9': '----.', '0': '-----', ',': '--..--', '.': '.-.-.-', 
    '?': '..--..', '/': '-..-.', '-': '-....-', '(': '-.--.', ')': '-.--.-', ' ': '/'
}

# Function to encode a message to Morse code
def encode_to_morse(message):
    try:
        morse_code = ''
        for char in message.upper():
            if char not in MORSE_CODE_DICT:
                raise ValueError(f"Character '{char}' cannot be encoded into Morse code.")
            morse_code += MORSE_CODE_DICT[char] + ' '
        return morse_code.strip()
    except ValueError as ve:
        print(ve)
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None

# Function to decode Morse code to a message
def decode_from_morse(morse_message):
    try:
        morse_words = morse_message.split(' / ')  # Words are separated by '/'
        decoded_message = ''
        for word in morse_words:
            for morse_char in word.split():
                if morse_char not in MORSE_CODE_DICT.values():
                    raise ValueError(f"Morse code '{morse_char}' is invalid.")
                decoded_message += list(MORSE_CODE_DICT.keys())[list(MORSE_CODE_DICT.values()).index(morse_char)]
            decoded_message += ' '
        return decoded_message.strip()
    except ValueError as ve:
        print(ve)
        return None
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        return None

# Main program loop
if __name__ == "__main__":
    while True:
        print("\nMorse Code Encoder/Decoder")
        print("1. Encode a message to Morse code")
        print("2. Decode Morse code to a message")
        print("3. Exit")

        try:
            choice = int(input("Select an option (1/2/3): "))
            if choice == 1:
                message = input("Enter a message to encode: ")
                result = encode_to_morse(message)
                if result:
                    print(f"Encoded Morse Code: {result}")
            elif choice == 2:
                morse_message = input("Enter Morse code to decode (use '/' for space between words): ")
                result = decode_from_morse(morse_message)
                if result:
                    print(f"Decoded Message: {result}")
            elif choice == 3:
                print("Goodbye!")
                break
            else:
                print("Invalid option. Please select 1, 2, or 3.")
        except ValueError:
            print("Please enter a valid number for selection.")
        except Exception as e:
            print(f"An unexpected error occurred: {e}")
