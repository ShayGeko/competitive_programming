struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        
        ListNode* merged = new ListNode();
        ListNode* cur = merged;
        while(list1 && list2){
            if(list1 -> val <= list2 -> val){
                cur-> next = list1;
                list1 = list1->next;
            }
            else{
                cur-> next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1? list1 : list2;
        
        cur = merged->next;
        delete merged;
        return cur;
    }
};