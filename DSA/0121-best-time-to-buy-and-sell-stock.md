# Best Time to Buy and Sell Stock - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/">121. Best Time to Buy and Sell Stock</a></h2><h3>Easy</h3><hr>

### Problem Statement:
You are given an array `prices` where `prices[i]` is the price of a given stock on day `i`. You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return the **maximum profit** you can achieve from this transaction. If no profit can be achieved, return `0`.

### Example 1:
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

### Example 2:
```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

### Constraints:
- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

---

### Approach: Single Pass Solution (Optimal)
- **Time Complexity**: O(n) where `n` is the length of the `prices` array. We traverse the array only once.
- **Space Complexity**: O(1) as we only use a constant amount of extra space.

The algorithm iterates through the list of prices while keeping track of the minimum price encountered so far and the maximum profit that can be made from any valid pair of buy and sell days.

### Code:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /brute force approach
//         int n = prices.size();
//         int profit = 0;
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         for(int i=0;i<n;i++){
//             if(prices[i]>maxi){
//                 maxi = prices[i];
//             }
//             if(prices[i]<mini){
//                 mini = prices[i];
//             }
//         }
//         int maxProfit = maxi - mini;
//         for(int i=0;i<n;i++){
            
//             for(int j=i+1;j<n;j++){
//                 int val = prices[j] - prices[i];
//                 profit = max(profit,val);
//                 if(profit==maxProfit){
//                     return profit;
//                 }
//             }
//         }
   
// return profit;
        int n = prices.size();
        if (n == 0) return 0;  // Edge case: If there are no prices
        
        int buy = prices[0];  // Track the minimum price to buy
        int maxProfit = 0;    // Track the maximum profit
        
        // Iterate through the prices starting from day 1
        for (int i = 1; i < n; i++) {
            // Calculate profit if selling on day i
            int sell = prices[i];
            int profit = sell - buy;
            
            // Update the maximum profit
            maxProfit = max(maxProfit, profit);
            
            // Update the minimum price to buy
            if (prices[i] < buy) {
                buy = prices[i];
            }
        }
        
        return maxProfit;
    }
};
```

### Explanation:
1. **Initialization**:
   - `buy` is initialized to the price on day 1 (`prices[0]`), which is the minimum price to buy the stock.
   - `maxProfit` is initialized to `0` since no profit can be made initially.
   
2. **Iterating through the array**:
   - For each price on day `i`, calculate the potential profit if we were to sell on that day (`profit = sell - buy`).
   - Update the maximum profit if the current profit is greater than the previously recorded maximum profit.
   - Also, update the `buy` price to the minimum value encountered so far, ensuring that we are buying at the lowest price before selling.

3. **Return**:
   - After traversing the array, return the maximum profit found.

### Edge Cases:
- If there is only one price or all prices are in decreasing order, no profit can be made, so return `0`.
- If the price array contains only increasing prices, the algorithm will correctly return the difference between the highest and lowest price.

---

### Example Walkthrough:
For `prices = [7,1,5,3,6,4]`:
- Day 1: Buy = 7, maxProfit = 0
- Day 2: Buy = 1 (updated), maxProfit = 0
- Day 3: Profit = 5 - 1 = 4, maxProfit = 4
- Day 4: Profit = 3 - 1 = 2, maxProfit = 4 (no update)
- Day 5: Profit = 6 - 1 = 5, maxProfit = 5 (updated)
- Day 6: Profit = 4 - 1 = 3, maxProfit = 5 (no update)

The final result is `maxProfit = 5`.

