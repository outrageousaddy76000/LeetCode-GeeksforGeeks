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
    map <int,pair<double,int>> m;
    void traverse(TreeNode *root,int level){
        if(root==NULL) return;
        m[level].first+=root->val;
        m[level].second++;
        traverse(root->left,level+1);
        traverse(root->right,level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        traverse(root,0);
        vector <double> ans;
        for(auto &pr:m){
            ans.push_back(pr.second.first/pr.second.second);
        }
        return ans;
    }
};