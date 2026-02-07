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
    void addRow(TreeNode *root, int &val, int &depth, int curr_level){
        if(root==nullptr) return;
        if(curr_level == depth-1){
            //add here
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            root->left = new TreeNode(val,left,nullptr);
            root->right = new TreeNode(val,nullptr, right);
        }
        else{
            addRow(root->left, val, depth, curr_level+1);
            addRow(root->right, val, depth, curr_level+1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) return new TreeNode(val, root, nullptr);
        else addRow(root, val, depth, 1);
        return root;
    }
};