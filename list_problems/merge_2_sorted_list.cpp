class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // checking if one of them is empty.
        if(!list1) { 
            return list2;
        }
        else if(!list2) {
            return list1;
        }
        ListNode* res = nullptr;
        if (list1->val <= list2->val) {
            res = list1;
            res->next = mergeTwoLists(list1->next, list2);
        }
        else {
            res = list2;
            res->next = mergeTwoLists(list1, list2->next);
        }
        return res;
    }
};
