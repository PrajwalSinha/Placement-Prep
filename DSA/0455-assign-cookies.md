# Find Content Children - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/assign-cookies/">455. Assign Cookies</a></h2><h3>Easy</h3><hr>

### Problem Statement:
Assume you are an employee at a company and you are given two lists:
- `g`, where `g[i]` is the greed factor of the `i-th` child (a child with a greed factor of `g[i]` can be content with a cookie of size `s[j]` if `s[j] >= g[i]`).
- `s`, where `s[j]` is the size of the `j-th` cookie.

Your goal is to maximize the number of content children. Return the maximum number of children who are content with their cookies.

### Example 1:
```
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of the children are [1, 2, 3]. The sizes of the cookies are [1, 1]. Only one child can be content, with a cookie of size 1.
```

### Example 2:
```
Input: g = [1,2,3], s = [2,2]
Output: 2
Explanation: You have 3 children and 2 cookies. The greed factors of the children are [1, 2, 3]. The sizes of the cookies are [2, 2]. Two children can be content, each with a cookie of size 2.
```

### Constraints:
- `1 <= g.length, s.length <= 3 * 10^4`
- `1 <= g[i], s[j] <= 2^31 - 1`

---

### Approach: Greedy Algorithm
- **Time Complexity**: O(n log n + m log m), where `n` is the number of children and `m` is the number of cookies. Sorting both lists takes O(n log n) and O(m log m) time.
- **Space Complexity**: O(1) if we exclude the space used for sorting.

The algorithm uses a two-pointer technique to match the smallest cookie that can satisfy each child's greed factor, ensuring that the maximum number of children are content.

### Code:
```cpp
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        
        sort(g.begin(), g.end()); // Sort children's greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        
        int l = 0; // Pointer for children
        int r = 0; // Pointer for cookies
        
        while (l < n && r < m) {
            if (g[l] <= s[r]) { // If current cookie can satisfy the current child
                l++; // Move to the next child
            }
            r++; // Move to the next cookie
        }
        
        return l; // l is the count of content children
    }
};
```

### Explanation:
1. **Sorting**:
   - Both `g` (children's greed factors) and `s` (cookie sizes) are sorted in ascending order.

2. **Two-Pointer Technique**:
   - `l` and `r` are pointers for iterating through the children and cookies, respectively.
   - If the current cookie (`s[r]`) can satisfy the current child's greed (`g[l]`), move to the next child (`l++`).
   - Always move to the next cookie (`r++`), regardless of whether the current cookie was used or not.

3. **Return**:
   - The value of `l` at the end of the loop represents the number of content children, as it counts how many children have been satisfied with cookies.

### Edge Cases:
- If there are more cookies than children, some cookies will remain unsused, but the result will be limited by the number of children.
- If there are more children than cookies, only as many children as there are cookies can be content.

This approach ensures that we efficiently maximize the number of content children with a time complexity of O(n log n + m log m).