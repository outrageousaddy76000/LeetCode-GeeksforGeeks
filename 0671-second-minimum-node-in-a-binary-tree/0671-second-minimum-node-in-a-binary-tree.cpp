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
    void pre(TreeNode *root){
        if(root==NULL) return;
        s.insert(root->val);
        pre(root->left);
        pre(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        pre(root);
        auto it = s.begin();
        if(s.size()<=1) return -1;
        advance(it, 1);
        return *it;
    }
};