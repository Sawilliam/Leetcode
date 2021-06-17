class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode* idx = head;
        int count = 0;
        while( 1 )
        {
            if(count == n+1){
                vec.erase(vec.begin());
            } else {
                count++;
            }
            vec.push_back(idx);
            if( NULL == idx->next)
                break;
            idx = idx->next;
        }
        
        if( n >= 2 ){
            if( vec.size() == n )
                return vec[1];
            
            vec[0]->next = vec[2];
        } else if ( vec.size() == 1 ){
            return NULL;
        } else {
            vec[0]->next = NULL;
        }
        
        return head;
    }
};