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
    int check(TreeNode * root,int current){
        if(root==NULL) return current;
        if(root->left==NULL && root->right==NULL){
            //we have found the leaf node
            current++;
            return current;
        }
        if(root->right==NULL){
            //right subtree doesnt exist
            current++;
            return check(root->left,current);
        }
        if(root->left==NULL){
            //left subtree doesnt exist
            current++;
            return check(root->right,current);
        }
        current++;
        return min(check(root->right,current),check(root->left,current));
    }
    int minDepth(TreeNode* root) {
        //as soon as we find a leaf node we return the length from the root
        int current =0;
        return check(root,current);
    }
};