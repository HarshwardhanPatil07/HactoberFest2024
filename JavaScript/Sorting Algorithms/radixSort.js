// Helper function to get the digit at a specific place value
function getDigit(num, place) {
    return Math.floor(Math.abs(num) / Math.pow(10, place)) % 10;
}

// Helper function to count the number of digits in a number
function digitCount(num) {
    if (num === 0) return 1;
    return Math.floor(Math.log10(Math.abs(num))) + 1;
}

// Helper function to find the maximum number of digits in an array
function mostDigits(nums) {
    let maxDigits = 0;
    for (let i = 0; i < nums.length; i++) {
        maxDigits = Math.max(maxDigits, digitCount(nums[i]));
    }
    return maxDigits;
}

// Radix Sort function
function radixSort(arr) {
    let maxDigitCount = mostDigits(arr);
    
    // Loop for every digit place (ones, tens, hundreds, etc.)
    for (let k = 0; k < maxDigitCount; k++) {
        // Create buckets for each digit (0-9)
        let digitBuckets = Array.from({ length: 10 }, () => []);

        // Place elements into the corresponding bucket based on the current digit
        for (let i = 0; i < arr.length; i++) {
            let digit = getDigit(arr[i], k);
            digitBuckets[digit].push(arr[i]);
        }

        // Flatten the buckets back into the array
        arr = [].concat(...digitBuckets);
    }

    return arr;
}

// Taking array input from the user
let input = prompt("Enter numbers separated by spaces:");
let array = input.split(' ').map(Number);  // Split input and convert to array of numbers

console.log("Sorted array:", radixSort(array));

//Contributed by Prasad Kandekar