class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tail = new ListNode();
        tail->next=head;

        while(head->next!=NULL){
            ListNode* h1=new ListNode(gcd(head->val,head->next->val));
            h1->next=head->next;
            head->next=h1;
            head=h1->next;
        }
        return tail->next;
    }
};
