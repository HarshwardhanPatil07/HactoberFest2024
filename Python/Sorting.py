class SortingAlgorithms:
    def __init__(self, arr):
        self.arr = arr
        self.steps = 0

    def reset_steps(self):
        self.steps = 0

    def bubble_sort(self):
        n = len(self.arr)
        self.reset_steps()
        for i in range(n):
            for j in range(0, n-i-1):
                self.steps += 1
                if self.arr[j] > self.arr[j+1]:
                    self.arr[j], self.arr[j+1] = self.arr[j+1], self.arr[j]

    def selection_sort(self):
        n = len(self.arr)
        self.reset_steps()
        for i in range(n):
            min_idx = i
            for j in range(i+1, n):
                self.steps += 1
                if self.arr[j] < self.arr[min_idx]:
                    min_idx = j
            self.arr[i], self.arr[min_idx] = self.arr[min_idx], self.arr[i]

    def insertion_sort(self):
        self.reset_steps()
        for i in range(1, len(self.arr)):
            key = self.arr[i]
            j = i - 1
            while j >= 0 and key < self.arr[j]:
                self.steps += 1
                self.arr[j + 1] = self.arr[j]
                j -= 1
            self.arr[j + 1] = key

    def merge_sort(self):
        if len(self.arr) > 1:
            mid = len(self.arr) // 2
            left_half = self.arr[:mid]
            right_half = self.arr[mid:]

            left_half_obj = SortingAlgorithms(left_half)
            right_half_obj = SortingAlgorithms(right_half)

            left_half_obj.merge_sort()
            right_half_obj.merge_sort()

            i = j = k = 0

            while i < len(left_half) and j < len(right_half):
                self.steps += 1
                if left_half[i] < right_half[j]:
                    self.arr[k] = left_half[i]
                    i += 1
                else:
                    self.arr[k] = right_half[j]
                    j += 1
                k += 1

            while i < len(left_half):
                self.arr[k] = left_half[i]
                i += 1
                k += 1

            while j < len(right_half):
                self.arr[k] = right_half[j]
                j += 1
                k += 1

    def quick_sort(self, low, high):
        if low < high:
            pivot_index = self.partition(low, high)
            self.quick_sort(low, pivot_index - 1)
            self.quick_sort(pivot_index + 1, high)

    def partition(self, low, high):
        pivot = self.arr[high]
        i = low - 1
        for j in range(low, high):
            self.steps += 1
            if self.arr[j] < pivot:
                i += 1
                self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
        self.arr[i + 1], self.arr[high] = self.arr[high], self.arr[i + 1]
        return i + 1

    def heap_sort(self):
        n = len(self.arr)
        self.reset_steps()
        for i in range(n // 2 - 1, -1, -1):
            self.heapify(n, i)
        for i in range(n - 1, 0, -1):
            self.arr[i], self.arr[0] = self.arr[0], self.arr[i]
            self.heapify(i, 0)

    def heapify(self, n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and self.arr[left] > self.arr[largest]:
            largest = left

        if right < n and self.arr[right] > self.arr[largest]:
            largest = right

        if largest != i:
            self.steps += 1
            self.arr[i], self.arr[largest] = self.arr[largest], self.arr[i]
            self.heapify(n, largest)

    def display(self):
        print("Sorted Array:", self.arr)
        print("Steps needed for sorting:", self.steps)

   


def radix_sort(self):
        max_num = max(self.arr)
        num_digits = len(str(max_num))
        
        # Initialize a bucket for each digit (0-9)
        buckets = [[] for _ in range(10)]
        
        for digit in range(num_digits):
            for num in self.arr:
                index = (num // 10 ** digit) % 10
                buckets[index].append(num)
            
            self.arr = []
            for bucket in buckets:
                self.arr.extend(bucket)
            
            buckets = [[] for _ in range(10)]



def counting_sort(self):

        max_num = max(self.arr)
        min_num = min(self.arr)
        range_of_values = max_num - min_num + 1

        count = [0] * range_of_values
        output = [0] * len(self.arr)

        for num in self.arr:
            count[num - min_num] += 1

        for i in range(1, range_of_values):
            count[i] += count[i - 1]

        for num in reversed(self.arr):
            output[count[num - min_num] - 1] = num
            count[num - min_num] -= 1

        self.arr = output


# Base example array
arr = [64, 34, 25, 12, 22, 11, 90]

# Initialize SortingAlgorithms object
sorting_obj = SortingAlgorithms(arr)

# Example usage of each sorting algorithm
print("Original Array:", arr)

# Bubble Sort
print("\nBubble Sort -")
sorting_obj.bubble_sort()
sorting_obj.display()

# Selection Sort
print("\nSelection Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.selection_sort()
sorting_obj.display()

# Insertion Sort
print("\nInsertion Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.insertion_sort()
sorting_obj.display()

# Merge Sort
print("\nMerge Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.merge_sort()
sorting_obj.display()

# Quick Sort
print("\nQuick Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.quick_sort(0, len(arr) - 1)
sorting_obj.display()

# Heap Sort
print("\nHeap Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.heap_sort()
sorting_obj.display()

# Radix Sort
print("\nRadix Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.radix_sort()
sorting_obj.display()

# Counting Sort
print("\nCounting Sort -")
sorting_obj = SortingAlgorithms(arr)  # Reset the array
sorting_obj.counting_sort()
sorting_obj.display()