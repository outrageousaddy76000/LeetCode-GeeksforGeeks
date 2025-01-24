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
    vector <vector<string>> ans;
    void fillans(int r, int c, TreeNode* root,int &height){
        ans[r][c]=to_string(root->val);
        if(root->left) fillans(r+1,c-pow(2,height-r-1),root->left, height);
        if(root->right) fillans(r+1,c+pow(2,height-r-1),root->right, height);
    }
    int getHeight(TreeNode *root){
        if(!root->left && !root->right){
            return 0;
        }
        if(!root->right) return 1+getHeight(root->left);
        if(!root->left) return 1+getHeight(root->right);
        return 1+max(getHeight(root->right),getHeight(root->left));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int m = height+1;
        int n = pow(2,height+1)-1;
        ans.resize(m, vector <string> (n));
        fillans(0,(n-1)/2,root,height);
        return ans;
    }
};