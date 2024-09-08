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
        vector <ListNode*> ans;
        ListNode* ptr=head;
        int cnt=0;
        while(ptr!=NULL){
            ptr=ptr->next;
            cnt++;
        }
        int div = cnt/k;
        int extra = cnt%k;
        ptr=head;
        for(int i=0;i<k;i++){
            //fill div elements, fill one more if extra
            int num=div;
            if(extra){
                num++;
                extra--;
            }
            if(ptr!=NULL){ 
                ans.push_back(ptr);    
                for(int j=0;j<num-1;j++){
                    ptr=ptr->next;
                }
                ListNode* temp = ptr;
                ptr=ptr->next;
                temp->next=NULL;
            }
            else ans.push_back(NULL);
        }
        return ans;
    }
};