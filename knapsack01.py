#srikavya15 Implementation of0/1 knapsack in dynamic programming in python 18-10-2024
#0/1 knapsack using dynamic programming 
def knapsack01(weights, profits, W, n): 
    dp=[[0 for _ in range(W+1)]for _ in range(n+1)] 
    for i in range(1,n+1): 
        for w in range(1,W+1): 
            if weights[i-1]<=w: 
                dp[i][w]=max(dp[i-1][w],profits[i-1]+dp[i-1][w-weights[i-1]]) 
            else: 
                dp[i][w]=dp[i-1][w] 

 
    max_value=dp[n][w] 
    selected_items = [] 
    w = W 
    for i in range(n, 0, -1): 
        if dp[i][w] != dp[i - 1][w]:   
            selected_items.append(i - 1)   
            w -= weights[i - 1]   
    selected_items.reverse() 
    return max_value, selected_items 
W = int(input('Enter the knapsack capacity: ')) 
n = int(input('Enter the number of items: ')) 
weights = [] 
profits = [] 
for i in range(n): 
    x = int(input(f'Enter weight of item {i + 1}: ')) 
    y = int(input(f'Enter profit of item {i + 1}: ')) 
    weights.append(x) 
    profits.append(y) 
print('Weights:', weights) 
print('Profits:', profits) 
max_value, selected_items = knapsack01(weights, profits, W, n) 
print(f"The maximum profit that can be obtained is: {max_value}") 
print(f"The selected items (1-based index) are: {[i + 1 for i in selected_items]}") 
