/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* head;
    int rec(ListNode* node){
        if (node->next==nullptr){
            if (node->val<5){
                node->val=2*node->val;
                return 0;
            }
            node->val=(node->val*2)%10;
            return 1;
        }
        int x = node->val*2+rec(node->next);
        if (x<10){
            node->val=x;
            return 0;
        }
        int y=x%10;
        node->val=y;
        return (x-y)/10;
    }
    ListNode* doubleIt(ListNode* h) {
        head=new ListNode(0,h);
        rec(head);
        return (head->val==0)?head->next:head;
    }
};
