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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue <pair<TreeNode*,int>> q;
        q.push({root,0});
        map <int,vector<int>> m;
        while(!q.empty()){
            pair <TreeNode*,int> p = q.front();
            q.pop();
            int level = p.second;
            TreeNode* treenode = p.first;
            if(level&1){
                m[level].push_back(treenode->val);
            }
            if(treenode->left!=NULL)
                q.push({treenode->left,level+1});
            if(treenode->right!=NULL)
                q.push({treenode->right,level+1});
        }
        q.push({root,0});
        int curr_index=0;
        int curr_level=0;
        while(!q.empty()){
            pair <TreeNode*,int> p = q.front();
            q.pop();
            int level = p.second;
            TreeNode* treenode = p.first;
            if(level&1){
                if(level>curr_level){
                    curr_level = level;
                    curr_index=0;
                    treenode->val=m[level][m[level].size()-1 - curr_index];
                    curr_index++;
                }
                else{
                    treenode->val=m[level][m[level].size()-1 - curr_index];
                    curr_index++;
                }
            }
            if(treenode->left!=NULL)
                q.push({treenode->left,level+1});
            if(treenode->right!=NULL)
                q.push({treenode->right,level+1});
        }
        //change values of levels based on elements of map
        return root;
    }
};