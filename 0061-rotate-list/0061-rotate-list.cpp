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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        ListNode *ptr=head;
        ListNode *last=NULL;
        while(ptr!=NULL){
            len++;
            if(ptr->next==NULL) last = ptr;
            ptr=ptr->next;
        }
        if(len<=1 || k%len==0) return head;
        k%=len;
        k=len-k-1;
        ptr=head;
        while(k--){
            ptr=ptr->next;          
        }
        ListNode *start = ptr->next;
        ptr->next=NULL;
        last->next=head;
        return start;
    }
};