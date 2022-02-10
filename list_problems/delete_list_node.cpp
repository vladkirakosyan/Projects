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
        ListNode* pr = node;
        while(pr != nullptr && pr->next != nullptr){
            pr->val = pr->next->val;
            if (pr->next->next == nullptr) {
                pr->next = nullptr;
            }
            pr = pr->next;
        }
    }
};
