# Problem: Longest Substring with At Most K Distinct Characters
# Question: Given a string s and an integer k, write a function to find the length of the longest substring that contains at most k distinct characters. If k is zero or the string is empty, return 0.

def longest_substring_k_distinct(s: str, k: int) -> int:
    if k == 0 or not s:
        return 0
    
    left = 0
    max_len = 0
    char_freq = {}

    # Expand the window with the right pointer
    for right in range(len(s)):
        char_freq[s[right]] = char_freq.get(s[right], 0) + 1

        # Shrink the window until we have at most k distinct characters
        while len(char_freq) > k:
            char_freq[s[left]] -= 1
            if char_freq[s[left]] == 0:
                del char_freq[s[left]]
            left += 1  # Move the left pointer to shrink the window

        # Update maximum length of substring found
        max_len = max(max_len, right - left + 1)

    return max_len

# Test cases
print(longest_substring_k_distinct("eceba", 2))        # Output: 3
print(longest_substring_k_distinct("aa", 1))           # Output: 2
print(longest_substring_k_distinct("aabbcc", 3))       # Output: 6
print(longest_substring_k_distinct("abcadcacacaca", 3))  # Output: 11
