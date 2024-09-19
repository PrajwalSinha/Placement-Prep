# Two Sum - LeetCode Problem

<h2><a href="https://leetcode.com/problems/two-sum/">1. Two Sum</a></h2><h3>Easy</h3><hr>

### Problem Statement:
Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

### Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

### Example 2:
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

### Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

### Constraints:
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- **Only one valid answer exists.**

---

### Approach 1: Brute Force (Commented Out in Code)
- **Time Complexity**: O(n^2)
- Iterate through each pair of numbers and check if their sum equals the target.
- Nested loops check all possible combinations of two numbers.
- **Drawback**: Inefficient for larger arrays.

### Approach 2: Sorting + Binary Search (Commented Out in Code)
- **Time Complexity**: O(n log n) due to sorting
- First, sort the array.
- For each element, use binary search to find the complement that sums to the target.
- **Drawback**: The sorting step adds unnecessary complexity, and binary search might not be as efficient compared to other methods.

### Approach 3: Optimal Solution (Implemented in Code)
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)
- Use a **hash map** to store the indices of the elements encountered so far.
- For each element `nums[i]`, check if the complement (`target - nums[i]`) exists in the map.
- If it does, return the indices of the two numbers.
- This approach ensures that each element is checked only once, making it highly efficient.

### Code (Optimal Approach):
```cpp
class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        //Brute Force approach
        // int rem;
        // vector<int> res;
        // for(int i=0;i<nums.size();i++){
        //     rem = target - nums[i];
        //     for(int j=0;j<nums.size();i++){
        //         if(rem==nums[j]){
        //             res.push_back(i);
        //             res.push_back(j);
        //         }
        //     }
        // }
        // return res;
        
        //Better Approach
//         int rem;
//         int low;
//         int high;
//         vector<int> res;
//         vector<int> sorted=nums;
//         sort(sorted.begin(),sorted.end());
//         for(int i=0;i<sorted.size();i++){
//             rem = target - sorted[i];
//             low = i;
//             high = sorted.size()-1;
            
//             while(low<=high){
//                 int mid = (low+high)/2;
//                 if(sorted[mid]==rem){
//                     res.push_back(i);
//                     res.push_back(mid);
//                 } else if(sorted[mid]<target){
//                     low = mid+1;
//                 } else{
//                     high = mid-1;
//                 }
//             }
            
//         }
//         return res;
        unordered_map<int, int> mpp;
        int rem;
        
        for(int i = 0; i < nums.size(); i++) {
            rem = target - nums[i];
            if(mpp.find(rem) != mpp.end()) {
                return {mpp[rem], i};
            }
            mpp[nums[i]] = i;
        }
        
        return {-1, -1};  // If no solution is found
    }
};
```

### Explanation:
- We iterate through the `nums` array.
- For each number `nums[i]`, compute its complement `rem = target - nums[i]`.
- If the complement is found in the hash map, return the current index `i` and the index of the complement.
- If not, store the current number and its index in the hash map for future reference.

