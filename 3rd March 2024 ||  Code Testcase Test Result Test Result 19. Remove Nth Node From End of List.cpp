class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next=head;
        ListNode* fast=start;
        ListNode* slow = start;
        
        for(int i=1; i<=n;++i){
            fast=fast->next;
        }
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* target=slow->next;
        slow->next=slow->next->next;
        
        delete target;
        return start->next;
    }
};
