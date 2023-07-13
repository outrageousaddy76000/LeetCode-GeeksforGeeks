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
    set <int> s;
    bool ans=true;
    void pre(TreeNode* root){
        if(root==NULL) return;
        s.insert(root->val);
        if(s.size()>1){
            ans=false;
            return;
        }
        pre(root->left);
        pre(root->right);

    }
    bool isUnivalTree(TreeNode* root) {
        pre(root);
        return ans;
    }
};