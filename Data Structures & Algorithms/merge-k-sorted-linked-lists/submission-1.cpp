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
    ListNode* mergingtwolists(ListNode*a,ListNode*b){
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;

        while(a!=nullptr && b!=nullptr){
            if(a->val<=b->val){
                temp->next=a;
                a=a->next;
            }
            else{
                temp->next=b;
                b=b->next;
            }
            temp=temp->next;
        }
        if(a!=nullptr){
            temp->next=a;
        }
        if(b!=nullptr){
            temp->next=b;
        }
        return dummy->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        if(n==0)
        return nullptr;

        while(n>1){
            int idx=0;
            for(int i=0;i<n;i+=2){
                if(i+1<n){
                    lists[idx++]=mergingtwolists(lists[i],lists[i+1]);
                }
                else{
                    lists[idx++]=lists[i];
                }
            }
            n=idx;
        }
        return lists[0];
        
    }
};
