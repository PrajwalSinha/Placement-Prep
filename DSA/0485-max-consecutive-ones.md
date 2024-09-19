# Find Max Consecutive Ones - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/max-consecutive-ones/">485. Max Consecutive Ones</a></h2><h3>Easy</h3><hr>

### Problem Statement:
Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

### Example 1:
```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The maximum number of consecutive 1s is 3.
```

### Example 2:
```
Input: nums = [1,0,1,1,0,1,1,1,1]
Output: 4
Explanation: The maximum number of consecutive 1s is 4.
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

---

### Approach: Counting Consecutive Ones
- **Time Complexity**: O(n), where `n` is the length of the input array. We traverse the array once.
- **Space Complexity**: O(1) if we exclude the space used by the result vector.

The algorithm counts consecutive `1`s while traversing the array, and keeps track of the maximum count found.

### Code:
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;       // To count the current sequence of consecutive 1s
        int maxCount = 0;    // To store the maximum count of consecutive 1s
        
        // Traverse the array
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                count++;   // Increase count for consecutive 1s
            } else {
                maxCount = max(maxCount, count); // Update maxCount if needed
                count = 0;  // Reset count for the next sequence
            }
        }
        
        // Final check to update maxCount in case the longest sequence ends at the end of the array
        return max(maxCount, count);
    }
};
```

### Explanation:
1. **Initialize Counters**:
   - `count` keeps track of the current sequence of consecutive `1`s.
   - `maxCount` stores the maximum length of such sequences encountered.

2. **Traverse the Array**:
   - If the current element is `1`, increment `count`.
   - If the current element is `0`, compare `count` with `maxCount` to possibly update `maxCount` and reset `count` to `0`.

3. **Final Update**:
   - After the loop, a final check ensures that the longest sequence of `1`s ending at the end of the array is considered.

### Edge Cases:
- If the array contains all `1`s, the maximum count should be the length of the array.
- If the array contains no `1`s, the maximum count should be `0`.

### Example Walkthrough:
For `nums = [1,1,0,1,1,1]`:
- Traverse the array and count consecutive `1`s:
  - `1,1` → count = 2
  - `0` → maxCount = 2, reset count to 0
  - `1,1,1` → count = 3
- The final maximum count of consecutive `1`s is `3`.

This approach efficiently computes the desired result in a single pass through the array.