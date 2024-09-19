# Longest Common Prefix - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/longest-common-prefix/">14. Longest Common Prefix</a></h2><h3>Easy</h3><hr>

### Problem Statement:
Write a function to find the **longest common prefix** string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

### Example 1:
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

### Example 2:
```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

### Constraints:
- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters.

---

### Approach: Iterative Prefix Shrinking
- **Time Complexity**: O(S) where `S` is the sum of all characters in the input strings.
- **Space Complexity**: O(1) excluding the space for the input and output.

The algorithm compares each string in the array with the current prefix. If the current string does not start with the prefix, the prefix is shortened by one character until a match is found or it becomes empty.

### Code:
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Return empty string if input array is empty
        if (strs.empty()) return "";

        // Set the prefix as the first string
        string prefix = strs[0];

        // Iterate through each string in the array
        for (int i = 1; i < strs.size(); i++) {
            // Reduce the prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by removing the last character
                prefix = prefix.substr(0, prefix.size() - 1);

                // If the prefix becomes empty, no common prefix exists
                if (prefix.empty()) return "";
            }
        }

        return prefix;  // Return the longest common prefix
    }
};
```

### Explanation:
1. **Step 1**: Start with the first string (`strs[0]`) as the initial prefix.
2. **Step 2**: Loop through the remaining strings in the array.
   - Check if the current string starts with the prefix using `find(prefix) == 0`.
   - If not, reduce the prefix by one character at a time until a match is found or the prefix becomes empty.
3. **Step 3**: If the prefix becomes empty at any point, return `""` since no common prefix exists.
4. **Step 4**: After processing all the strings, return the longest common prefix.

---

### Edge Cases:
- If the input list is empty, return an empty string.
- If any string does not share a common prefix, return an empty string.
- If all strings are the same, the entire string is the common prefix.

### Example Walkthrough:
For `["flower", "flow", "flight"]`:
- Start with `prefix = "flower"`.
- Compare with `"flow"`: shorten to `"flow"`.
- Compare with `"flight"`: shorten to `"fl"`.
- Return `"fl"` as the longest common prefix.

