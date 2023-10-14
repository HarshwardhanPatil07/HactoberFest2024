#  Github username : Prathamesh-510
#  Here I created a simple python file in which all sorting algorithms in the python are discussed.


# Function for Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    comparisons = 0
    swaps = 0
    for i in range(n):
        for j in range(0, n - i - 1):
            comparisons += 1
            if arr[j] > arr[j + 1]:
                swaps += 1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return comparisons, swaps

# Function for Selection Sort
def selection_sort(arr):
    n = len(arr)
    comparisons = 0
    swaps = 0
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            comparisons += 1
            if arr[j] < arr[min_index]:
                min_index = j
        swaps += 1
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return comparisons, swaps

# Function for Insertion Sort
def insertion_sort(arr):
    comparisons = 0
    swaps = 0
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            comparisons += 1
            swaps += 1
            arr[j + 1] = arr[j]
            j -= 1
        swaps += 1
        arr[j + 1] = key
    return comparisons, swaps

# Function for Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return 0, 0
    comparisons = 0
    swaps = 0
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    left_comp, left_swaps = quick_sort(left)
    right_comp, right_swaps = quick_sort(right)
    comparisons += left_comp + right_comp
    swaps += left_swaps + right_swaps
    return comparisons, swaps

# Function for Merge Sort
def merge_sort(arr):
    comparisons = 0
    swaps = 0
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        left_comp, left_swaps = merge_sort(left_half)
        right_comp, right_swaps = merge_sort(right_half)
        comparisons += left_comp + right_comp
        swaps += left_swaps + right_swaps

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            comparisons += 1
            if left_half[i] < right_half[j]:
                swaps += 1
                arr[k] = left_half[i]
                i += 1
            else:
                swaps += 1
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            swaps += 1
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            swaps += 1
            arr[k] = right_half[j]
            j += 1
            k += 1
    return comparisons, swaps

# Input a list of numbers
input_list = [int(x) for x in input("Enter a list of numbers separated by spaces: ").split()]

# Choose the sorting algorithm (e.g., bubble_sort, selection_sort, insertion_sort, quick_sort, or merge_sort)
algorithm_name = "Merge Sort"  # Change this to the desired sorting algorithm
sorted_list = input_list.copy()
comparisons, swaps = 0, 0

if algorithm_name == "Bubble Sort":
    comparisons, swaps = bubble_sort(sorted_list)
elif algorithm_name == "Selection Sort":
    comparisons, swaps = selection_sort(sorted_list)
elif algorithm_name == "Insertion Sort":
    comparisons, swaps = insertion_sort(sorted_list)
elif algorithm_name == "Quick Sort":
    comparisons, swaps = quick_sort(sorted_list)
elif algorithm_name == "Merge Sort":
    comparisons, swaps = merge_sort(sorted_list)

# Print the sorted list and the number of comparisons and swaps
print("Sorted list:", sorted_list)
print(f"Comparisons: {comparisons}, Swaps: {swaps}")
