# Product of Array Except Self - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/product-of-array-except-self/">238. Product of Array Except Self</a></h2><h3>Medium</h3>

### Problem Statement:
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

You must solve it **without using division** and in O(n) time complexity.

### Example 1:
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation: The product of all elements except nums[0] is 2*3*4 = 24.
The product of all elements except nums[1] is 1*3*4 = 12.
The product of all elements except nums[2] is 1*2*4 = 8.
The product of all elements except nums[3] is 1*2*3 = 6.
```

### Example 2:
```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
Explanation: The product of all elements except nums[0] is 1*0*3 = 0.
The product of all elements except nums[1] is -1*0*3 = 0.
The product of all elements except nums[2] is -1*1*3 = 9.
The product of all elements except nums[3] is -1*1*0 = 0.
The product of all elements except nums[4] is -1*1*0 = 0.
```

### Constraints:
- `2 <= nums.length <= 1000`
- `-30 <= nums[i] <= 30`
- The problem can be solved in O(n) time and O(1) space complexity (excluding the space used for output).

---

### Approach: Prefix and Suffix Products
- **Time Complexity**: O(n) where `n` is the length of the input array `nums`. We make a few passes through the array.
- **Space Complexity**: O(n) for the additional arrays used for prefix and suffix products. This can be optimized to O(1) if we use the output array to store suffix products in place.

The algorithm computes prefix and suffix products and combines them to find the final result without using division.

### Code:
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prePro(n, 1);  // Prefix products
        vector<int> postPro(n, 1); // Suffix products
        
        // Compute prefix products
        for (int i = 1; i < n; ++i) {
            prePro[i] = prePro[i - 1] * nums[i - 1];
        }
        
        // Compute suffix products
        for (int i = n - 2; i >= 0; --i) {
            postPro[i] = postPro[i + 1] * nums[i + 1];
        }
        
        vector<int> ans(n);
        // Compute the result using prefix and suffix products
        for (int i = 0; i < n; ++i) {
            ans[i] = prePro[i] * postPro[i];
        }
        
        return ans;
    }
};
```

### Explanation:
1. **Prefix Products**:
   - Compute the product of all elements before the current index and store in `prePro`.

2. **Suffix Products**:
   - Compute the product of all elements after the current index and store in `postPro`.

3. **Result Computation**:
   - Multiply the prefix and suffix products for each index to get the final result.

### Optimized Approach (Space Complexity O(1)):
Instead of using two extra arrays, we can optimize space usage by storing the suffix products in the result array itself and calculating the final product in a single pass.

### Optimized Code:
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); // Result array initialized to 1

        // Compute prefix products and store in ans
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        
        // Compute suffix products and multiply with prefix products in ans
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        
        return ans;
    }
};
```

### Explanation of Optimized Approach:
1. **Compute Prefix Products**:
   - Iterate through the array and store the prefix product of all elements before the current index in `ans`.

2. **Compute Suffix Products**:
   - Iterate through the array in reverse and multiply the suffix product of all elements after the current index with the existing value in `ans`.

3. **Result**:
   - The final result in `ans` combines both prefix and suffix products for each index.

### Edge Cases:
- Arrays with all elements being the same.
- Arrays containing `0` and negative numbers.
