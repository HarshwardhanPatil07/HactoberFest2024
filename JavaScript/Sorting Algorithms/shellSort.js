function shellSort(arr) {
    let n = arr.length;
    
    // Start with a big gap, then reduce the gap
    for (let gap = Math.floor(n / 2); gap > 0; gap = Math.floor(gap / 2)) {
        // Perform a gapped insertion sort for this gap size
        for (let i = gap; i < n; i++) {
            let temp = arr[i];
            let j;
            
            // Shift earlier gap-sorted elements until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Place temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
    return arr;
}

// Taking array input from the user
let input = prompt("Enter numbers separated by spaces:");
let array = input.split(' ').map(Number);  // Split input and convert to array of numbers

console.log("Sorted array:", shellSort(array));


//contributed by Prasad Kandekar