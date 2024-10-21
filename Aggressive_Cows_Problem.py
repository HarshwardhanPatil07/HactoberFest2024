def canPlaceCows(stalls, cows, distance):
    count = 1  # Place the first cow in the first stall
    last_position = stalls[0]

    for i in range(1, len(stalls)):
        if stalls[i] - last_position >= distance:
            count += 1
            last_position = stalls[i]
            if count == cows:  # All cows are placed
                return True
    return False

def aggressiveCows(stalls, cows):
    stalls.sort()  # Sort the stall positions
    low = 1  # Minimum possible distance
    high = stalls[-1] - stalls[0]  # Maximum possible distance
    best_distance = 0

    while low <= high:
        mid = (low + high) // 2  # Midpoint distance

        if canPlaceCows(stalls, cows, mid):
            best_distance = mid  # Update best distance
            low = mid + 1  # Try for a bigger distance
        else:
            high = mid - 1  # Try for a smaller distance

    return best_distance

# Example usage
stalls = [1, 2, 4, 8, 9]
cows = 3
print(aggressiveCows(stalls, cows))  # Output: 3
