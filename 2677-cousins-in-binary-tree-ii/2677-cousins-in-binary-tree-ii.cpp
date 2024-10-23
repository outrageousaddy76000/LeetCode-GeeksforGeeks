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
private:
    void helper(TreeNode* root, vector <int> &sums, int level){
        if(level==0) root->val=0;
        if(root->left && root->right){
            (root->left)->val = sums[level+1]-(root->left)->val-(root->right)->val;
            (root->right)->val = (root->left)->val;
            helper(root->left,sums,level+1);
            helper(root->right,sums,level+1);
        }
        else if(root->left){
            (root->left)->val = sums[level+1]-(root->left)->val;
            helper(root->left,sums,level+1);
        }
        else if(root->right){
            (root->right)->val = sums[level+1]-(root->right)->val;
            helper(root->right,sums,level+1);
        }
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector <int> sums;
        queue <pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair <TreeNode*,int> p = q.front();
            q.pop();
            if(p.first->left) q.push({p.first->left,p.second+1});
            if(p.first->right) q.push({p.first->right,p.second+1});
            if(p.second>=sums.size()){
                sums.push_back(p.first->val);
            }
            else sums[p.second]+=p.first->val;
        }
        helper(root,sums,0);
        return root;
    }
};