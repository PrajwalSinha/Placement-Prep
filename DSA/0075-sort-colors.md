# Sort Colors - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/sort-colors/">75. Sort Colors</a></h2><h3>Medium</h3><hr>

### Problem Statement:
Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem **without** using the library's sort function.

### Example 1:
```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

### Example 2:
```
Input: nums = [2,0,1]
Output: [0,1,2]
```

### Constraints:
- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.

---

### Approach: Counting Colors with Hash Map (Implemented in Code)
- **Time Complexity**: O(n) where `n` is the length of the input array `nums`. We traverse the array twice, once to count the occurrences and another to overwrite the array with sorted values.
- **Space Complexity**: O(1) (in terms of additional space, ignoring the input array). The space for the hash map counts as extra space, but no additional space grows with the size of the input.

In this approach, we use an unordered map to count the frequency of each color (represented by `0`, `1`, and `2`) and then overwrite the original array with sorted colors based on the frequency.

### Code:
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // Count the occurrences of each color
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        int index = 0;
        
        // Overwrite the array with 0s (red)
        for (int i = 0; i < mp[0]; ++i) {
            nums[index++] = 0;
        }
        
        // Overwrite the array with 1s (white)
        for (int i = 0; i < mp[1]; ++i) {
            nums[index++] = 1;
        }
        
        // Overwrite the array with 2s (blue)
        for (int i = 0; i < mp[2]; ++i) {
            nums[index++] = 2;
        }
    }
};
```

### Explanation:
1. **Step 1**: Create an unordered map to count the occurrences of each number (0, 1, 2) in the `nums` array.
2. **Step 2**: Traverse through the `nums` array to populate the map with the counts for each color.
3. **Step 3**: Overwrite the original array:
   - First, overwrite the first `mp[0]` elements with `0`.
   - Then, overwrite the next `mp[1]` elements with `1`.
   - Finally, overwrite the remaining `mp[2]` elements with `2`.
   
### Edge Cases:
- If the array contains only one type of color (e.g., all `0`s or all `1`s), the solution will still work.
- The map ensures that all counts are accurate before overwriting the array.

### Alternative Approach: Dutch National Flag Algorithm (Optimal)
A more optimal solution with **O(n) time complexity** and **O(1) space complexity** is the **Dutch National Flag Algorithm**, which uses three pointers to partition the array in a single pass. This method avoids the need for additional data structures like a hash map.