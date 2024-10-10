#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to find the minimum number of meeting rooms required
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    
    // Sort the intervals by their start time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    
    // Min-heap to keep track of end times of meetings
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Add the end time of the first meeting
    minHeap.push(intervals[0][1]);
    
    // Iterate over the remaining meetings
    for (int i = 1; i < intervals.size(); i++) {
        // If the meeting can start after the earliest ended meeting, remove it from the heap
        if (intervals[i][0] >= minHeap.top()) {
            minHeap.pop();
        }
        
        // Push the current meeting's end time into the heap
        minHeap.push(intervals[i][1]);
    }
    
    // The size of the heap tells us the minimum number of rooms required
    return minHeap.size();
}

int main() {
    vector<vector<int>> meetings = {{0, 30}, {5, 10}, {15, 20}, {12, 25}, {25, 30}};
    
    cout << "Minimum number of meeting rooms required: " << minMeetingRooms(meetings) << endl;
    
    return 0;
}

// This file was contributed by: Drupitha-Chandrashekar 
//Aim: To determine the minimum number of meeting rooms required so that no two meetings overlap.
//Date: 11-10-2024
