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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue <pair<TreeNode*,long long int>> q;
        q.push({root,0});
        vector <long long int> v;
        while(!q.empty()){
            pair <TreeNode*,long long int> p = q.front();
            q.pop();
            if(p.second+1>v.size()){
                v.push_back(p.first->val);
            }
            else v[p.second]+=p.first->val;
            if(p.first->left) q.push({p.first->left,p.second+1});
            if(p.first->right) q.push({p.first->right,p.second+1});
        }
        if(v.size()<k) return -1;
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};