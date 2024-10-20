function mergeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    // Find the middle point and divide the array into two halves
    const mid = Math.floor(arr.length / 2);
    const left = arr.slice(0, mid);
    const right = arr.slice(mid);

    // Recursively sort both halves
    const sortedLeft = mergeSort(left);
    const sortedRight = mergeSort(right);

    // Merge the sorted halves
    return merge(sortedLeft, sortedRight);
}

function merge(left, right) {
    let result = [];
    let i = 0;
    let j = 0;

    // Compare elements from both halves and merge them in sorted order
    while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
            result.push(left[i]);
            i++;
        } else {
            result.push(right[j]);
            j++;
        }
    }

    // Collect any remaining elements in either half
    while (i < left.length) {
        result.push(left[i]);
        i++;
    }

    while (j < right.length) {
        result.push(right[j]);
        j++;
    }

    return result;
}

// Taking array input from the user
let input = prompt("Enter numbers separated by spaces:");
let array = input.split(' ').map(Number);  // Split input and convert to array of numbers

console.log("Sorted array:", mergeSort(array));

//Contributed by Prasad Kandekar