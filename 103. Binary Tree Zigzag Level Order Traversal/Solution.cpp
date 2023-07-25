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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        //bfs
        queue <pair<TreeNode *,int>> q;
        q.push({root,0});
        int level=0;
        vector <int> v;
        while(!q.empty()){
            pair<TreeNode*,int> curr =  q.front();
            if(level!=curr.second){
                ans.push_back(v);
                v.clear();
                level++;
                v.push_back(curr.first->val);
                q.pop();
                if(curr.first->left!=NULL) q.push({curr.first->left,level+1});
                if(curr.first->right!=NULL) q.push({curr.first->right,level+1});
            }
            else{
                v.push_back(curr.first->val);
                q.pop();
                if(curr.first->left!=NULL) q.push({curr.first->left,level+1});
                if(curr.first->right!=NULL) q.push({curr.first->right,level+1});
            }
        }
        if(v.size()) ans.push_back(v);
        for(int i=0;i<ans.size();i++){
            if(i&1) reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};