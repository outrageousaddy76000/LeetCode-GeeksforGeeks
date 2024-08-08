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
    int ans;
    pair <int,int> helper(TreeNode* root){
        if(root==NULL) return {0,0};
        if(!root->left && !root->right){
            ans++;
            return {root->val,1};
        }
        pair<int,int> f1 = helper(root->left);
        pair<int,int> f2 = helper(root->right);
        int sum = f1.first+f2.first+root->val;
        int len = 1 + f1.second + f2.second;
        if(sum/len==root->val) ans++;
        return {sum,len};
    }
    int averageOfSubtree(TreeNode* root) {
        ans=0;
        helper(root);
        return ans;
    }
};