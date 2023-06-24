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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sumeach=0;
        ListNode* ans = NULL;
        int s1=0;
        int s2=0;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        while(ptr1!=NULL){
            ptr1=ptr1->next;
            s1++;
        }
        while(ptr2!=NULL){
            ptr2=ptr2->next;
            s2++;
        }
        if(s1>=s2){
            ListNode* temp1 = l1;
            ListNode* temp2 = l2;
            while(temp2!=NULL){
                sumeach = carry+temp1->val+temp2->val;
                temp1=temp1->next;
                temp2=temp2->next;
                carry = sumeach/10;
                int ins = sumeach%10;
                //insert in answer list
                ListNode *newnode = new ListNode();
                newnode->val=ins;
                newnode->next=NULL;
                if(ans==NULL){
                    ans = newnode;
                }
                else{
                    ListNode *temp = ans;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
            while(temp1!=NULL){
                sumeach = carry+temp1->val;
                temp1=temp1->next;
                carry = sumeach/10;
                int ins = sumeach%10;
                //insert in answer list
                ListNode *newnode = new ListNode();
                newnode->val=ins;
                newnode->next=NULL;
                if(ans==NULL){
                    ans = newnode;
                }
                else{
                    ListNode *temp = ans;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
        }
        else{
            ListNode* temp1 = l1;
            ListNode* temp2 = l2;
            while(temp1!=NULL){
                sumeach = carry+temp1->val+temp2->val;
                temp1=temp1->next;
                temp2=temp2->next;
                carry = sumeach/10;
                int ins = sumeach%10;
                //insert in answer list
                ListNode *newnode = new ListNode();
                newnode->val=ins;
                newnode->next=NULL;
                if(ans==NULL){
                    ans = newnode;
                }
                else{
                    ListNode *temp = ans;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
            while(temp2!=NULL){
                sumeach = carry+temp2->val;
                temp2=temp2->next;
                carry = sumeach/10;
                int ins = sumeach%10;
                //insert in answer list
                ListNode *newnode = new ListNode();
                newnode->val=ins;
                newnode->next=NULL;
                if(ans==NULL){
                    ans = newnode;
                }
                else{
                    ListNode *temp = ans;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
            }
        }
        //insert carry in reverse
        if(carry!=0){
            ListNode *newnode = new ListNode();
            newnode->val = carry;
            newnode->next = NULL;
            if(ans==NULL){
                ans = newnode;
            }
            else{
                ListNode *temp = ans;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=newnode;
            }
        }
        return ans;
    }
};