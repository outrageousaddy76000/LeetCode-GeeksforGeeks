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
    ListNode* mergeNodes(ListNode* head) {
        vector <int> nodes;
        ListNode *ptr = head->next;
        int ans=0;
        while(ptr!=NULL){
            if(ptr->val==0){
                nodes.push_back(ans);
                ans=0;
            }
            else{
                ans+=ptr->val;
            }
            ptr=ptr->next;
        }
        ptr=NULL;
        ListNode *res=NULL;
        for(auto &val:nodes){
            ListNode *newnode = new ListNode(val);
            if(ptr==NULL){
                ptr = newnode;
                res=ptr;
            }
            else {
                ptr->next = newnode;
                ptr=ptr->next;
            }
        }
        return res;
    }
};