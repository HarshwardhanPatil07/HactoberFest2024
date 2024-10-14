
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        stack<int> st;
        int n = nums.size();
        int prev = INT_MIN;  // This keeps track of the '2' in the 132 pattern
        for (int i = n - 1; i >= 0; i--)
        {
            // If nums[i] is less than the last '2' found, return true
            if (nums[i] < prev) return true;
            
            // Update the '2' value by popping from the stack
            while (!st.empty() && st.top() < nums[i])
            {
                prev = st.top();
                st.pop();
            }
            // Push the current element (potential '3') to the stack
            st.push(nums[i]);
        }
        return false;
    }
};
