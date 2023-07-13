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
    bool check(TreeNode *root, int x,int y){
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        if(root->right==NULL) return check(root->left,x,y);
        else if(root->left==NULL) return check(root->right,x,y);
        if((((root->left)->val)==x && ((root->right)->val)==y) || (((root->left)->val)==y  && ((root->right)->val)==x)) return false;
        return check(root->left,x,y) & check(root->right,x,y);
    }
    int depth(TreeNode *root,int x,int level){
        if(root->val==x) return level;
        if(root->left==NULL && root->right==NULL) return 0;
        if(root->left==NULL) return depth(root->right,x,level+1);
        if(root->right==NULL) return depth(root->left,x,level+1);
        return max(depth(root->left,x,level+1),depth(root->right,x,level+1));
    }
    bool isCousins(TreeNode* root, int x, int y) {
        //should have same depth
        if(depth(root,x,0)!=depth(root,y,0)) return false;
        //should not have same parent
        if(check(root,x,y)) return true;
        return false;
    }
};