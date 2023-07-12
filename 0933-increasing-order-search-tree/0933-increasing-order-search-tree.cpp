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
    vector <int> nodes;
    void pre(TreeNode *root){
        if(root==NULL) return;
        pre(root->left);
        nodes.push_back(root->val);
        pre(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        pre(root);
        TreeNode *ans= new TreeNode(nodes[0]);
        TreeNode *ptr = ans;
        int i=1;
        while(i<nodes.size()){
            ptr->right= new TreeNode(nodes[i]);
            ptr=ptr->right;
            i++;
        }
        return ans;
    }
};