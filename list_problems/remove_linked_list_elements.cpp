class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        if(head->val == val) {
            ListNode* h = head;
            head = head->next;
            h->next = nullptr;
            delete h;
        }
        ListNode* f = head;
        while(f != nullptr && f->next != nullptr)
        {
            if(f->next->val == val) {
                ListNode* tmp = f->next;
                f->next = f->next->next;
                tmp->next = nullptr;
                delete tmp;
            }
            else {
                f = f->next;
            }
        }
        
        return head;

    }
};
