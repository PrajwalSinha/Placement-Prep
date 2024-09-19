# Delete Node in a Linked List - LeetCode Problem README

<h2><a href="https://leetcode.com/problems/delete-node-in-a-linked-list/">237. Delete Node in a Linked List</a></h2><h3>Medium</h3><hr>

### Problem Statement:
Write a function to **delete a node** in a singly-linked list. You will **not** be given access to the head of the list; instead, you will be given access to the node to be deleted **directly**.

It is **guaranteed** that the node to be deleted is **not a tail node** in the list.

### Example 1:
```
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
```

### Example 2:
```
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
```

### Constraints:
- The number of the nodes in the given list is in the range `[2, 1000]`.
- Each node in the list has a unique value.
- The node to be deleted will **not be the tail** and it will always be a valid node of the linked list.
- Do not return anything from your function.

---

### Approach: Overwrite and Remove the Next Node
- **Time Complexity**: O(1) - The solution operates in constant time, as it only updates the value and next pointer of the node.
- **Space Complexity**: O(1) - No extra space is required, only the node itself is modified.

Since you don't have access to the head of the linked list, the only way to "delete" the current node is to overwrite its value with the value of the next node and then bypass the next node by adjusting the pointer.

### Code:
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        
        // Remove the next node by linking the current node to the node after next
        node->next = node->next->next;
    }
};
```

### Explanation:
1. **Copy the Next Node's Value**:
   - To simulate deleting the current node, you first copy the value of the next node into the current node.
   
2. **Bypass the Next Node**:
   - Update the current node's `next` pointer to point to the node after the next one, effectively removing the next node from the list.

### Edge Cases:
- The node to be deleted is never the tail node, so you can always access `node->next`.
- The node to be deleted is guaranteed to be a valid node in the list, so no need for null checks.

---

### Example Walkthrough:
For a linked list `[4 -> 5 -> 1 -> 9]`, given node = `5`:
1. The value of node `5` is overwritten with `1` (the value of the next node).
2. The node `5` (now holding the value `1`) is linked to the node `9` (bypassing the original node `1`).
   
Result: The modified list is `[4 -> 1 -> 9]`.