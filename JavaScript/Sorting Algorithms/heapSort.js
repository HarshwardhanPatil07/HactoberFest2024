function heapSort(arr) {
    let n = arr.length;

    // Build a max heap
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (let i = n - 1; i > 0; i--) {
        // Move the current root (largest) to the end
        [arr[0], arr[i]] = [arr[i], arr[0]];

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }

    return arr;
}

// Heapify a subtree rooted at index i, size of heap is n
function heapify(arr, n, i) {
    let largest = i;  // Initialize largest as root
    let left = 2 * i + 1;  // Left child
    let right = 2 * i + 2;  // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and heapify
    if (largest !== i) {
        [arr[i], arr[largest]] = [arr[largest], arr[i]];  // Swap

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Taking array input from the user
let input = prompt("Enter numbers separated by spaces:");
let array = input.split(' ').map(Number);  // Split input and convert to array of numbers

console.log("Sorted array:", heapSort(array));


//contributed by Prasad Kandekar