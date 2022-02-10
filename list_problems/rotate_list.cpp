class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    if(!head || k == 0) return head;
 
        ListNode* cur = head;
        int len = 1;
        while(cur->next != nullptr)
        {
            ++len;
            cur = cur -> next;
        }
        cur->next = head;
        k = len - k % len;
        while(k--){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        
        return head;
    }
};
// works in every case
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
// works fine if k is less than size of list
