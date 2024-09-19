# Contains Duplicate II - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/contains-duplicate-ii/">219. Contains Duplicate II</a></h2><h3>Easy</h3><hr>

### Problem Statement:
Given an integer array `nums` and an integer `k`, return `true` if there are **two distinct indices** `i` and `j` in the array such that `nums[i] == nums[j]` and the **absolute difference** between `i` and `j` is at most `k`.

### Example 1:
```
Input: nums = [1,2,3,1], k = 3
Output: true
Explanation: The value 1 appears at indices 0 and 3, whose absolute difference is 3, which is <= k.
```

### Example 2:
```
Input: nums = [1,0,1,1], k = 1
Output: true
Explanation: The value 1 appears at indices 1 and 2, whose absolute difference is 1, which is <= k.
```

### Example 3:
```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
Explanation: The value 1 appears at indices 0 and 3, but their absolute difference is 3, which is > k.
```

### Constraints:
- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
- `0 <= k <= 10^5`

---

### Approach: Hash Map for Efficient Lookup
- **Time Complexity**: O(n), where `n` is the number of elements in the array. Each element is processed once.
- **Space Complexity**: O(n), where `n` is the number of elements in the array. Space is used for the hash map.

The algorithm uses a hash map to keep track of the most recent index of each element as it iterates through the array. This allows for efficient checking of the distance between indices where duplicate values are found.

### Code:
```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // Map to store the most recent index of each value
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (mp.count(nums[i])) { // Check if the current value is in the map
                if (abs(i - mp[nums[i]]) <= k) { // Check the difference of indices
                    return true;
                }
            }
            mp[nums[i]] = i; // Update the most recent index of the value
        }
        
        return false; // No valid pair found
    }
};
```

### Explanation:
1. **Hash Map Initialization**:
   - `mp` is an unordered map that stores the most recent index of each value encountered in the array.

2. **Iteration and Checking**:
   - For each element in the array, check if it exists in the map.
   - If it exists, check if the difference between the current index and the stored index is within the allowed range `k`.
   - If so, return `true`.

3. **Update Map**:
   - Update the map with the current index for the value.

4. **Final Return**:
   - If no such pair is found by the end of the loop, return `false`.

### Edge Cases:
- **Array Length**: If the array length is 1 or less, it cannot contain any duplicates with a distance of `k`.
- **Large `k` Values**: If `k` is larger than or equal to the length of the array, any duplicate within the array will be valid.

This approach efficiently determines the presence of nearby duplicates with a single pass through the array and constant-time lookups in the hash map.