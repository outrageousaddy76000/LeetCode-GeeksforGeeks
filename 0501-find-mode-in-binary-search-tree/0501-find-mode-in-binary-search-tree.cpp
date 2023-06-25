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
        pre(root->left);
        v.push_back(root->val);
        pre(root->right);
    } 
    vector<int> findMode(TreeNode* root) {
        pre(root);
        unordered_map <int,int> m;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        vector <int> ans;
        int maxi=INT_MIN;
        for(auto &pr:m){
            maxi = max(maxi,pr.second);
        }
        for(auto &pr:m){
            if(pr.second==maxi){
                ans.push_back(pr.first);
            }
        }        
        return ans;
    }
};