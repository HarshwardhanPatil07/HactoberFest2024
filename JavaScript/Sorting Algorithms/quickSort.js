function quickSort(arr) {
    if (arr.length <= 1) {
        return arr; // Base case: array is already sorted
    }

    // Select the pivot (choosing the last element here)
    let pivot = arr[arr.length - 1];
    let left = [];
    let right = [];

    // Partitioning the array into two halves: elements less than or greater than the pivot
    for (let i = 0; i < arr.length - 1; i++) {
        if (arr[i] < pivot) {
            left.push(arr[i]);
        } else {
            right.push(arr[i]);
        }
    }

    // Recursively sort the left and right halves and concatenate them with the pivot
    return [...quickSort(left), pivot, ...quickSort(right)];
}

// Taking array input from the user
let input = prompt("Enter numbers separated by spaces:");
let array = input.split(' ').map(Number);  // Split input and convert to array of numbers

console.log("Sorted array:", quickSort(array));

//Contributed by Prasad Kandekar