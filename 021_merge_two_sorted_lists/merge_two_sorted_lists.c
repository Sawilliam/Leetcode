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
    int Switch(ListNode*& big, ListNode*& small)
    {
        int rtn = 0; 
        while( small->next != NULL && small->next->val < big->val)
            small = small->next;
        ListNode *smalltmp = small->next;
        ListNode *bigtmp = big;
        if(!big->next)  /* Find the end of ListNode */
            rtn = 1;
        big = big->next;
        small->next = bigtmp;
        if(smalltmp == NULL) /* Find the end of ListNode */
            rtn = 1;
        else
            bigtmp->next = smalltmp;
        if(rtn)
            return 1;
        return 0;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( l1 == NULL || l2 == NULL){
            return NULL==l1 ? l2 : l1;
        }
        ListNode *l1dx = l1, *l2dx = l2;
        while(1)
        {
            if( l1dx-> val >= l2dx->val ){
                if(Switch(l1dx, l2dx))
                    break;

            } else {
                if(Switch(l2dx, l1dx))
                    break;
            }
        }
        
        return l1->val >= l2->val ? l2 : l1;
        
        
    }
};