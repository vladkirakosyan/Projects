class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* f = head->next;
        ListNode* s = head;
        while(f != nullptr && f->next != nullptr)
        {
            if(f == s) return true;
            f = f->next->next;
            s = s->next;
        }
        return false;
    }
};
