
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        auto prehead = new ListNode(0, head);
        auto cur = prehead;
        ListNode* temp;
        while(cur -> next && cur->next->next){
            temp = cur->next;
            cur->next = cur->next->next;
            temp->next = cur->next->next;
            cur->next->next = temp;
            
            cur = cur->next->next;
        }
        
        head = prehead->next;
        delete prehead;
        
        return head;
    }
};