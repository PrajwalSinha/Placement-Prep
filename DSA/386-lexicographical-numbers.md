## Problem: Lexicographical Numbers (LeetCode #386)

<h2><a href="https://leetcode.com/problems/lexicographical-numbers/">386. Lexicographical Numbers</a></h2><h3>Medium</h3><hr>


### Problem Description:
Given an integer `n`, return the integers from `1` to `n` in lexicographical order.

### Example:
**Input:** `n = 13`  
**Output:** `[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]`

### Constraints:
- 1 ≤ n ≤ 5 * 10^4

---

## Approach:

The solution generates numbers in lexicographical order by using a **depth-first search (DFS)**-like approach. The key idea is to explore every valid number starting from `1` to `9`, and then recursively append digits (`0` to `9`) to form the next lexicographical number.

### Steps:

1. **Recursive function (DFS traversal)**:  
   The recursive function `generate` helps in building numbers by recursively multiplying the current number by 10 and adding digits (`0` to `9`) until we exceed the given limit `n`.

2. **Initial loop**:  
   The main function (`lexicalOrder`) initiates the recursive DFS for all starting digits (`1` to `9`).

3. **Pruning**:  
   If the next generated number exceeds the limit `n`, recursion stops.

---

## Code Explanation:

```cpp
class Solution {
private:
    // Recursive function to generate lexicographical numbers
    void generate(int current, int limit, vector<int>& ans){
        if(current > limit) return; // Base case: stop recursion if number exceeds n
        
        ans.push_back(current); // Add current number to the answer list

        // Loop through digits 0-9 to form next possible numbers
        for(int next=0 ; next <= 9 ; next++){
            int nextNumber = current * 10 + next; // Generate the next number
            
            // Recursively call the function if nextNumber is within the limit
            if(nextNumber <= limit){
                generate(nextNumber, limit, ans);
            }
            else break; // Prune the recursion if nextNumber exceeds the limit
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans; // This will store the result
        
        // Start DFS with numbers 1 through 9 as initial values
        for(int begin = 1 ; begin <= 9 ; begin++){
            generate(begin, n, ans);
        }

        return ans; // Return the lexicographically ordered numbers
    }
};
```

### Explanation of Key Functions:

1. **`generate(int current, int limit, vector<int>& ans)`**:  
   - A helper function to recursively generate numbers by expanding the current number with all possible digits (`0-9`). It stops when the next number exceeds the given limit `n`.

2. **`lexicalOrder(int n)`**:  
   - Initializes the result vector and calls `generate()` for each starting digit (`1` to `9`). Finally, it returns the result.

---

## Time Complexity:
- The time complexity is **O(n)** because each number from `1` to `n` is processed exactly once in lexicographical order.

## Space Complexity:
- The space complexity is **O(n)** due to the storage required for the result vector, `ans`, and the recursion stack.

---

## Why This Works:
This approach works because it mimics the process of lexicographically generating numbers. Starting from `1`, we explore each number by appending digits in a depth-first manner, which naturally leads to lexicographical order without needing sorting.

