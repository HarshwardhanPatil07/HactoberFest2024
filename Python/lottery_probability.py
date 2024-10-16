import itertools
import math
from collections import Counter

def factorial(n):
    """Calculate the factorial of a number."""
    return math.factorial(n)

def combinations(n, k):
    """Calculate the number of combinations of choosing k elements from a set of n elements."""
    return factorial(n) / (factorial(k) * factorial(n - k))

def calculate_probability(n, k):
    """Calculate the probability of selecting k numbers from a pool of n numbers."""
    total_combinations = combinations(n, k)
    return 1 / total_combinations

def analyze_frequency(numbers_list, pool_size, select_size):
    """
    Analyze the frequency of numbers in the list and calculate probabilities for the most frequent numbers.
    
    :param numbers_list: A list of lottery numbers
    :param pool_size: The total number of numbers in the lottery pool (e.g., 60 for a pool from 1 to 60)
    :param select_size: The number of numbers drawn in the lottery (e.g., 6 in a 6/60 lottery)
    :return: Dictionary with number frequencies and probability of each number being drawn.
    """
    # Count the frequency of each number in the list
    frequency = Counter(numbers_list)
    
    # Calculate probabilities for the most frequent numbers
    total_combinations = combinations(pool_size, select_size)
    
    # Calculate probability for each number based on its frequency
    probabilities = {}
    for number, freq in frequency.items():
        individual_prob = (freq / len(numbers_list)) * (1 / total_combinations)
        probabilities[number] = individual_prob
    
    return probabilities

def most_likely_numbers(probabilities, top_n=5):
    """
    Return the top_n most likely numbers based on their probability.
    
    :param probabilities: Dictionary with number probabilities
    :param top_n: Number of top probable numbers to return
    :return: List of top_n most likely numbers
    """
    # Sort numbers by probability in descending order
    sorted_probabilities = sorted(probabilities.items(), key=lambda x: x[1], reverse=True)
    return sorted_probabilities[:top_n]

def main():
    # Example lottery numbers list from previous draws
    numbers_list = [12, 34, 7, 34, 22, 5, 19, 34, 7, 9, 22, 5, 12, 7, 19, 9, 5, 22]
    
    # Settings for a lottery: pool size (e.g., 60 numbers) and selection size (e.g., 6 drawn numbers)
    pool_size = 60
    select_size = 6
    
    # Analyze frequencies and calculate probabilities
    probabilities = analyze_frequency(numbers_list, pool_size, select_size)
    
    # Get the most likely numbers based on probability
    top_numbers = most_likely_numbers(probabilities, top_n=5)
    
    print("Most likely numbers based on past frequency:")
    for num, prob in top_numbers:
        print(f"Number: {num}, Probability: {prob:.10f}")

if __name__ == "__main__":
    main()
