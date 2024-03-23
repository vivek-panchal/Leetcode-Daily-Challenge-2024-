// STEP 1: Divide the linked list in 2 equal parts.
// STEP 2: Reverse the second half of the linked list.
// STEP 3: Now merge the first half of the list between the reversed other half of the list.

class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while(head != NULL){
            next = head->next;
            head-> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void reorderList(ListNode* head){
        ListNode* mid = getMiddle(head);
        ListNode* reversed = reverse(mid->next);
        mid->next = NULL;
        
        
        
        while(head != NULL and reversed != NULL){
            ListNode* node1 = head->next;
            ListNode* node2 = reversed->next;
            head->next = reversed;
            reversed->next = node1;
            head= node1;
            reversed = node2;
        }
    }
};
