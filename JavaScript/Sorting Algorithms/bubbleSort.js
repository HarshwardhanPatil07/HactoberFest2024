function bubbleSort(arr) {
    let n = arr.length;
    let swapped;

    do {
        swapped = false;  // Reset swapped flag
        for (let i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap arr[i] and arr[i + 1]
                [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
                swapped = true;  // Set swapped flag
            }
        }
        n--;  // Reduce the size of the array to consider (last element is sorted)
    } while (swapped);

    return arr;
}

// Taking array input from the user
let input = prompt("Enter numbers separated by spaces:");
let array = input.split(' ').map(Number);  // Split input and convert to array of numbers

console.log("Sorted array:", bubbleSort(array));


//Contributed by Prasad Kandekar