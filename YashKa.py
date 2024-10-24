# Merge Sort Algorithm in Python

def merge_sort(arr):
    # Base case: if the array has only one element, it is already sorted
    if len(arr) > 1:
        
        # Finding the middle of the array
        mid = len(arr) // 2
        
        # Dividing the array into two halves
        left_half = arr[:mid]
        right_half = arr[mid:]
        
        # Recursively sorting both halves
        merge_sort(left_half)
        merge_sort(right_half)
        
        i = j = k = 0
        
        # Merge the two halves back together
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
        
        # If any elements are left in the left half
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        
        # If any elements are left in the right half
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

# Test the merge sort algorithm
arr = [12, 11, 13, 5, 6, 7]
print("Given array:", arr)

merge_sort(arr)
print("Sorted array:", arr)
