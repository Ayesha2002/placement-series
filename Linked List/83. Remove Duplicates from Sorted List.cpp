class Solution {
public:
    ListNode* ret(ListNode* n,int value){
        while(n && n->val == value){
            n=n->next;
        }
        return n;

    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* x = head;
        while(x){
            x->next = ret(x,x->val);
            x=x->next;
        }
        return head;
        
    }
};
