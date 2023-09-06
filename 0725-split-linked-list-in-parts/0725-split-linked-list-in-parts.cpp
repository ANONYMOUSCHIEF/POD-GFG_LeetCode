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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int i=0;
        ListNode * temp=head;
        while(temp){
            i++;
            temp=temp->next;
        }
        int len=i/k,rem=i%k;
        
        vector<ListNode*>res(k,NULL);
        for(int i=0;i<k;i++){
            res[i]=head;
            ListNode * prev=NULL;
            for(int j=0;j<(len + (i<rem));j++){
                prev=head;
                head=head->next;
            }
            if(!head) break;
            if(prev) prev->next=NULL;
        }
        return res;
        
    }
};