class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* cur = head;
        ListNode* wait = head;
        int len = 1;
        int x = k;
        while(cur->next != nullptr)
        {
            len++;
            cur = cur -> next;
            if (x > 0){
                x--;
                wait = wait -> next;
            }
        }
        cur->next = head;
        head = wait->next;
        wait->next = nullptr;
        return head;
    }
};
