#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of keywords
char *keywords[] = { "if", "else", "while", "int", "return", "void", "main", "char", "float" };
int numKeywords = 9;

// Function to check if a string is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<');
}

// Function to check if a character is a special symbol
int isSpecialSymbol(char ch) {
    return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == ',');
}

// Function to check if a string is a number
int isNumber(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Lexical analyzer function
void lexicalAnalyzer(char *source) {
    char buffer[100]; // Buffer to store words and identifiers
    int i = 0, j = 0;

    while (source[i] != '\0') {
        // Skip white spaces
        if (isspace(source[i])) {
            i++;
            continue;
        }

        // Check if it's a letter or digit (start of identifier or keyword)
        if (isalpha(source[i])) {
            j = 0;
            // Accumulate characters to form a word (identifier or keyword)
            while (isalnum(source[i])) {
                buffer[j++] = source[i++];
            }
            buffer[j] = '\0';

            // Check if the accumulated string is a keyword
            if (isKeyword(buffer))
                printf("<KEYWORD, %s>\n", buffer);
            else
                printf("<IDENTIFIER, %s>\n", buffer);
        }
        // Check if it's a number
        else if (isdigit(source[i])) {
            j = 0;
            // Accumulate digits to form a number
            while (isdigit(source[i])) {
                buffer[j++] = source[i++];
            }
            buffer[j] = '\0';

            printf("<NUMBER, %s>\n", buffer);
        }
        // Check if it's an operator
        else if (isOperator(source[i])) {
            printf("<OPERATOR, %c>\n", source[i]);
            i++;
        }
        // Check if it's a special symbol
        else if (isSpecialSymbol(source[i])) {
            printf("<SPECIAL SYMBOL, %c>\n", source[i]);
            i++;
        }
        // Handle unrecognized characters
        else {
            printf("<UNKNOWN, %c>\n", source[i]);
            i++;
        }
    }
}

int main() {
    // Example input source code
    char sourceCode[] = "int main() { int a = 5; if (a > 2) a = a + 1; return 0; }";

    printf("Lexical Analysis of Source Code:\n");
    lexicalAnalyzer(sourceCode);

    return 0;
}
