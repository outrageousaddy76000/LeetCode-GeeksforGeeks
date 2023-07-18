/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int x;
    TreeNode *ans;
    void find(TreeNode *root){
        if(root==NULL) return;
        if(root->val==x){
            ans=root;
            return;
        }
        find(root->left);
        find(root->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        x = target->val;
        find(cloned);
        return ans;
    }
};