// its-amans
// DSA
// 12/10/2024

//code studio problem link : https://www.naukri.com/code360/problems/aggressive-cows_1082559

bool possiblesolution(vector<int> &stalls, int n, int k, int mid){
    int cowcount = 1; // Starting with 1 cow at the first stall
    int lastpos = stalls[0]; // Position of the last placed cow
    
    for(int i = 1; i < n; i++){ // Start from the second stall
        if((stalls[i] - lastpos) >= mid){
            cowcount++;
            lastpos = stalls[i]; // Update the last cow's position
        }
        if(cowcount == k){ // If we've placed all cows
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    // Sort the stalls positions
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int max = stalls[stalls.size() - 1]; // Max stall position
    int n = stalls.size();

    // Limiting Case: if cows are more than stalls, return -1
    if(n < k){
        return -1;
    }

    int e = max;
    int ans = -1;
    int mid = s + (e - s) / 2;

    // Binary search to find the largest minimum distance
    while(s <= e){
        if(possiblesolution(stalls, n, k, mid)){
            ans = mid; // Possible solution found, try for larger distance
            s = mid + 1;
        } else {
            e = mid - 1; // Try for smaller distance
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
