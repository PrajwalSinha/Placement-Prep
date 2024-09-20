# Longest Common Prefix - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/xor-queries-of-a-subarray/"> XOR Queries of a Subarray</a></h2><h3>Medium</h3><hr>

### Intuition
The problem can be optimized by recognizing that XOR has a useful property: if we have a prefix XOR of the array, then we can calculate the XOR of any subarray in constant time. This avoids recalculating the XOR for each query, making the solution more efficient.

### Approach
1. First, compute the prefix XOR for the array `arr`. The prefix XOR at index `i` gives the XOR of all elements from index `0` to `i`.
2. For each query, which asks for the XOR of elements between indices `start` and `end`, we can compute this in constant time using the prefix XOR array:
   - If `start == 0`, the XOR is simply `prefixXor[end]`.
   - Otherwise, the XOR for the subarray is `prefixXor[end] ^ prefixXor[start - 1]`.

### Complexity

- **Time complexity:**  
  - Precomputing the prefix XOR takes \(O(n)\), where \(n\) is the size of `arr`.  
  - Answering each query takes \(O(1)\), and with \(q\) queries, the total time complexity is \(O(n + q)\).

- **Space complexity:**  
  - The prefix XOR array requires \(O(n)\) extra space, and the result array requires \(O(q)\) space for storing the answers, making the total space complexity \(O(n + q)\).

### Code
```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;

        // Step 1: Calculate the prefix XOR
        vector<int> prefixXor(n);
        prefixXor[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }

        // Step 2: Answer each query in constant time
        for(auto& query : queries){
            int start = query[0];
            int end = query[1];
            if(start == 0){
                ans.push_back(prefixXor[end]);
            } else {
                ans.push_back(prefixXor[start - 1] ^ prefixXor[end]);
            }
        }

        return ans;
    }
};
```