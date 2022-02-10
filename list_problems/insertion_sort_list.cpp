class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) 
		return nullptr;
	ListNode * ptr = head;
        ListNode * it = head;
        while(ptr){
            it = head;
            while(it != ptr)
            {
                if(ptr->val < it->val){
                    int min = ptr->val;
                    ptr->val = it->val;
                    it->val = min;
                }
                it = it->next;
            }
            ptr = ptr->next;
        }
        return head;
    }
};
