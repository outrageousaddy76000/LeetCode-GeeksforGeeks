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
    void insert(int data, TreeNode *root){
        if(root->val>data){
            if(root->left==NULL){
                //insert in the left subtree
                root->left = new TreeNode(data);
            }
            else{
                insert(data,root->left);
            }
        }
        else{
            if(root->right==NULL){
                //insert in the right subtree
                root->right= new TreeNode(data);
            }
            else{
                insert(data,root->right);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        insert(val,root);
        return root;
    }
};