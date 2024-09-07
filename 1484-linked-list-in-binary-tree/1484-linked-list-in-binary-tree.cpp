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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector <TreeNode*> ptr;
    void find(int x, TreeNode* root){
        if(root==NULL) return;
        if(root->val==x) ptr.push_back(root);
        find(x,root->left);
        find(x,root->right);
    }
    bool build(TreeNode * root, ListNode * head){
        if(head==NULL) return true;
        if(root==NULL) return false;
        bool ans=false;
        if(root->val==head->val){
            ans=true;
            ans&= (build(root->left,head->next) || build(root->right,head->next));
        }
        return ans;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        //find head->val in tree
        ptr.clear();
        find(head->val,root);
        if(ptr.size()==0) return false;
        //for all the starting points,try to build the tree
        bool ans=false;
        for(auto &node:ptr){
            ans|=build(node,head);
        }
        return ans;
    }
};