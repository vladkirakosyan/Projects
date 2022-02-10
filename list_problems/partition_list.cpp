class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return nullptr;
        ListNode* p1 = new ListNode();
        ListNode* p2 = new ListNode();
        ListNode* first = p1;
        ListNode* mid = p2;
        while (head){
            if(head->val < x){
                p1->next = head;
                p1 = p1 ->next;
            }
            else{
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = nullptr;
        p1->next = mid->next;
        return first->next;
    }
};
