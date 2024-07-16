/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode *x, vector <TreeNode*> &path){
        //if(dfs(right)|| dfs(left)){
            //return true
        //else pop and return false
        if(root==NULL) return false;
        path.push_back(root);
        if(root==x) return true;
        if(dfs(root->left,x,path) || dfs(root->right,x,path)){
            return true;
        }
        else{
            path.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector <TreeNode *> pathstart,pathdest;
        dfs(root,p,pathstart);
        dfs(root,q,pathdest);
        map <TreeNode *,int> m;
        for(auto &val:pathdest){
            m[val]++;
        }
        TreeNode *lca=NULL;
        reverse(pathstart.begin(),pathstart.end());
        for(auto &val:pathstart){
            if(m.find(val)!=m.end()){
                lca=val;
                break;
            }
        }
        return lca;
    }
};