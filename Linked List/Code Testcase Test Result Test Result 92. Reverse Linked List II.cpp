
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if left is equal to right, no reversal is needed
        if(left == right) return head;
        
    
        vector<int> vec;
        ListNode *p = head;
        while(p) {
            vec.push_back(p->val);
            p = p->next;
        }
        reverse(vec.begin() + left - 1, vec.begin() + right);
        
        ListNode *head2 = nullptr, *tail = nullptr;
        for(int i : vec) {
            ListNode *node = new ListNode(i);
            if(!head2) {
                head2 = node;
                tail = head2;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }
        
        return head2;
    }
};
