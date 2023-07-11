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
    vector <int> v;
    void pre(TreeNode *root){
        if(root==NULL) return;
        v.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        pre(root);
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]<ans){
                ans=v[i]-v[i-1];
            }
        }
        return ans;
    }
};