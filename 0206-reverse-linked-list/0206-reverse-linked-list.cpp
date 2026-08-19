/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* revUsingRecursion(ListNode* prev, ListNode* curr) {
        // Base Case
        if(curr == NULL)  return prev;

        // Ek case ham solve krange baki recursion sambhal lega
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;

        // Recursive call
        ListNode* recursionKaAns = revUsingRecursion(prev, curr);

        return recursionKaAns;
    }
    ListNode* reverseList(ListNode* head) {
        // Using Recursion
        ListNode* prev = NULL;
        ListNode* curr = head;

        return revUsingRecursion(prev, curr);
    }
};