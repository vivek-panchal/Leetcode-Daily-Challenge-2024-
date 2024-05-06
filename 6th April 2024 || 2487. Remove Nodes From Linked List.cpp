class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* back = NULL;
        ListNode* front = NULL;
        while(curr!=NULL){
            front = curr->next;
            curr->next = back;
            back = curr;
            curr= front;
        }
        return back;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = reverse(head);
        ListNode* prev = newHead;
        ListNode* p = newHead;
        int maxi = newHead->val;
        p = p->next;
        while(p!=NULL){
            if(p->val < maxi){
                prev->next = p->next;
            }
            else{
                maxi = p->val;
                prev = p;
            }
            p = p->next;
        }
        return reverse(newHead);
    }
};
