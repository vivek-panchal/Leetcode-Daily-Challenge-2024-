class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* dummy=new ListNode(0);
        ListNode* ptr=dummy;
        
        ListNode* temp=head->next;
        int sum=0;
       
        while(temp!=NULL){
            
            while(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }
            
            ptr->next=new ListNode(sum);
            ptr=ptr->next;
            
            temp=temp->next;
            sum=0;
        }
        return dummy->next;
        
    }
};
