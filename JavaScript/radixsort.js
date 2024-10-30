
//function to find the no of digits in a number
function digitCount(n){
	if(n===0) return 1
		return Math.floor(Math.log10(Math.abs(n)))+1
}

//function to find the largest nunmber digit in the list of numbers 
function mostDigits(nums){
	var maxDigits=0
	for(let i=0;i<nums.length;i++){
		maxDigits=Math.max(maxDigits,digitCount(nums[i]))
	}
	return maxDigits
}

//function to find out the digit the required place value
function getDigit(num,place){
	return Math.floor(Math.abs(num)/Math.pow(10,place))%10
}


function radixSort(arr){
	//lets find out how many times to do the loop
     let maxdigitcount=mostDigits(arr)
     console.log(maxdigitcount)
     for(let k=0;k<maxdigitcount;k++){
     	//lets create buckets(0 to 9 ) like we will have 10 subarrays inside an array
     	var buckets=Array.from({length:10},()=>[])
     	//lets the get the digits at the k place and sort them into the buckets
     	for(let i=0;i<arr.length;i++){
           buckets[getDigit(arr[i],k)].push(arr[i])
     	}
     	//we will be modifiying the array input of the radix sort
     	arr=[].concat(...buckets)
     }
     
     return arr

}
