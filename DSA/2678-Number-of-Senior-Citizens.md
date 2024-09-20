# Senior Citizen Counter - README

<h2><a href="https://leetcode.com/problems/number-of-senior-citizens/"> Number of Senior Citizens</a></h2><h3>Easy</h3><hr>

## Problem Overview
The task is to determine the number of senior citizens (people aged over 60) based on a list of details provided as strings. Each string contains specific information, including the age of a person. The age is always stored at specific positions in each string, and our goal is to extract this information and count how many people are seniors.

## Solution Explanation

### Intuition
The details of each person are provided in a structured format, where characters at positions 11 and 12 represent the tens and units place of the person's age, respectively. Given this consistent format, we can directly access these characters, convert them to integers, and check if the age is greater than 60. 

### Approach
1. **Initialize a Counter:** Start by initializing a counter `ans` to keep track of how many senior citizens (people over 60 years old) are present.
2. **Iterate Over the List:** Loop through each string in the input list `details`.
3. **Extract Age Information:** For each string, extract the characters at positions 11 and 12, which represent the tens and units of the age. Convert these characters into an integer value.
4. **Check Age Condition:** If the age is greater than 60, increment the counter `ans`.
5. **Return Result:** Once all strings have been processed, return the value of `ans`, which represents the total number of senior citizens.

### Code
```cpp
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0; i < details.size(); i++) {
            string temp = details[i];
            char c1 = temp[11];  // tens place of age
            char c2 = temp[12];  // units place of age
            if(c1 == '6' && c2 > '0') {  // check if age is between 61-69
                ans++;
            }
            else if(c1 > '6') {  // check if age is 70 or greater
                ans++;
            }
        }
        return ans;
    }
};
```

### Example
**Input:**
```cpp
vector<string> details = {"ABCD1234567890", "EFGH9876543212", "IJKL6754321061"};
```
Here, the age information for each string:
- `"ABCD1234567890"` has age 78
- `"EFGH9876543212"` has age 54
- `"IJKL6754321061"` has age 61

**Output:** 
```cpp
2  // There are 2 senior citizens with ages 78 and 61.
```

## Complexity Analysis
### Time Complexity: O(n)
- The algorithm iterates through each string in the `details` vector exactly once, where `n` is the number of strings. Therefore, the time complexity is \( O(n) \).

### Space Complexity: O(1)
- The algorithm only uses a few extra variables (like `ans`, `c1`, and `c2`), which do not depend on the size of the input. Hence, the space complexity is \( O(1) \).

## Usage

1. **Input:** 
   - A vector of strings, where each string represents the details of a person. The age information is always located at positions 11 and 12 of the string.

2. **Output:** 
   - The function returns an integer representing the number of people whose age is greater than 60.

## Edge Cases
- The strings are consistently formatted, so no checks for malformed strings are necessary.
- If no one is a senior citizen, the function returns `0`.
- If the input list `details` is empty, the function also returns `0`.

## Conclusion
This solution efficiently counts the number of senior citizens from a list of details by extracting and comparing the age information from the structured strings. With a time complexity of \( O(n) \) and a space complexity of \( O(1) \), it is optimal for this problem.