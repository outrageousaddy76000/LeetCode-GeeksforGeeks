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
    map <int,int> m;
    int depth(TreeNode *root){
        if(root==NULL) return 0;
        if(m.find(root->val)!=m.end()) return m[root->val];
        return m[root->val] = 1+max(depth(root->left),depth(root->right));
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(depth(root->left)==depth(root->right)) return root;
        else if(depth(root->right)>depth(root->left)) return lcaDeepestLeaves(root->right);
        else return lcaDeepestLeaves(root->left);
    }
};