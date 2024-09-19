# Majority Element - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/majority-element/">169. Majority Element</a></h2><h3>Easy</h3><hr>

### Problem Statement:
Given an array `nums` of size `n`, return the **majority element**.

The majority element is the element that appears **more than** `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

### Example 1:
```
Input: nums = [3,2,3]
Output: 3
```

### Example 2:
```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

### Constraints:
- `n == nums.length`
- `1 <= n <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`
- The majority element always exists in the array.

---

### Approach 1: Hash Map (Implemented in Code)
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- Use an **unordered map** to count the frequency of each element.
- Traverse the array and populate the map where keys represent elements of the array and values represent their respective counts.
- Identify the element that has the highest frequency.

### Code:
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // Populate the map with frequency of each element
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        // Find the maximum frequency
        int maxi = INT_MIN;
        for (auto pair : mp) {
            if (pair.second > maxi) {
                maxi = pair.second;
            }
        }
        
        // Return the element that has the maximum frequency
        for (auto it : mp) {
            if (it.second == maxi) {
                return it.first;
            }
        }
        
        return -1;  // In case no majority element is found (although this won't happen given the problem constraints)
    }
};
```

### Explanation:
1. **Step 1**: Create an unordered map (`mp`) to store the frequency of each element in the input array `nums`.
2. **Step 2**: Traverse the array `nums` and increment the count of each element in the map.
3. **Step 3**: Iterate over the map to find the element with the highest frequency (`maxi`).
4. **Step 4**: Return the element whose frequency matches the maximum count.

### Alternative Approaches:
1. **Boyer-Moore Voting Algorithm**: This is an optimal approach with O(n) time and O(1) space complexity. It finds the majority element in a single pass through the array and without using extra space.