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
public:
    bool ans=false;
    void find(TreeNode *root, TreeNode *subroot){
        if(ans==true) return;
        if(root==NULL) return;
        if(root->val==subroot->val){
            ans=check(root,subroot);
        }
        if(ans==true) return;
        find(root->left,subroot);
        find(root->right,subroot);
    }
    bool check(TreeNode *root, TreeNode *subroot){
        if(subroot==NULL && root==NULL) return true;
        if(subroot==NULL && root!=NULL) return false;
        if(root==NULL && subroot!=NULL) return false;
        if(root->val != subroot->val) return false;
        return check(root->left,subroot->left) && check(root->right,subroot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        find(root,subRoot);
        return ans;        
    }
};