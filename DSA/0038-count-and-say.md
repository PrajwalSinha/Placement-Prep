# Count and Say - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/count-and-say/">38. Count and Say</a></h2><h3>Medium</h3><hr>

### Problem Statement:
The **Count and Say** sequence is a sequence of digit strings defined by the recursive formula:
- `countAndSay(1) = "1"`
- `countAndSay(n)` is the way you would "say" the string from `countAndSay(n-1)`, which is then converted into a new string.

To "say" a string, you count consecutive groups of the same digit, then say the count followed by the digit.

### Example 1:
```
Input: n = 1
Output: "1"
Explanation: This is the base case for the sequence.
```

### Example 2:
```
Input: n = 4
Output: "1211"
Explanation: 
countAndSay(1) = "1"
countAndSay(2) = say "1" → "11"
countAndSay(3) = say "11" → "21"
countAndSay(4) = say "21" → "1211"
```

### Constraints:
- `1 <= n <= 30`

---

### Approach: Iterative Character Grouping
- **Time Complexity**: O(n * m) where `m` is the length of the generated sequence at step `n`. For large `n`, the string grows exponentially.
- **Space Complexity**: O(m) where `m` is the length of the final sequence.

The idea is to generate the sequence iteratively starting from `n = 1`. At each step, the current string is used to construct the next string by counting consecutive characters and saying how many of each character exists.

### Code:
```cpp
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";  // Base case for n = 1
        if (n == 2) return "11"; // Base case for n = 2
        
        // Initialize the string for n = 2
        string str = "11";
        
        // Loop from n = 3 to the required n
        for (int i = 3; i <= n; i++) {
            string t = "";
            str = str + '&'; // Add a dummy character at the end to handle the last group
            int count = 1;   // Initialize count for the current character group
            
            // Traverse the current string and build the next sequence
            for (int j = 1; j < str.length(); j++) {
                if (str[j] != str[j - 1]) {
                    // Append the count and the character to the new string
                    t = t + to_string(count);
                    t = t + str[j - 1];
                    count = 1; // Reset the count for the next group
                } else {
                    // Increment the count for the current group of characters
                    count++;
                }
            }
            
            // Update str for the next iteration
            str = t;
        }
        
        return str;  // Return the result for n
    }
};
```

### Explanation:
1. **Base Case**: 
   - For `n = 1`, the result is `"1"`.
   - For `n = 2`, the result is `"11"` (one "1").
   
2. **Iterative Process**:
   - Start with `str = "11"` for `n = 2`.
   - For each subsequent `n`, generate the next string by counting consecutive characters in the current string and "saying" them.
   - Add a dummy character (`&`) at the end of the string to handle the last group of characters.
   
3. **String Construction**:
   - For each group of consecutive characters, append the count followed by the character to a new string.
   - Continue this process until the desired `n` is reached.

### Edge Cases:
- For `n = 1` and `n = 2`, handle directly with base cases.
- The string grows exponentially with `n`, but the constraints ensure that the approach will work within the given limits.

### Example Walkthrough:
For `n = 5`:
- `countAndSay(1) = "1"`
- `countAndSay(2) = "11"`
- `countAndSay(3) = "21"`
- `countAndSay(4) = "1211"`
- `countAndSay(5) = "111221"`

