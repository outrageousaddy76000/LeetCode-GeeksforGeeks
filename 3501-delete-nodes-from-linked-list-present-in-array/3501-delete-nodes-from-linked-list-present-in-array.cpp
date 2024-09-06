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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map <int,int> m;
        for(auto &val:nums) m[val]++;
        while(m.find(head->val)!=m.end()) head=head->next;
        if(head==NULL) return head;
        //delete next nodes
        ListNode *ptr=head;
        while(ptr!=NULL && ptr->next!=NULL){
            while(ptr->next!=NULL && m.find(ptr->next->val)!=m.end()){
                ptr->next = ptr->next->next;
            }
            ptr=ptr->next;
        }
        return head;
    }
};