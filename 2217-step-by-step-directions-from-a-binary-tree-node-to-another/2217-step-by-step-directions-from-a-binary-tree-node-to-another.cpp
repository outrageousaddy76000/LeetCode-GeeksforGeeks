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
    void findnode(TreeNode *root, TreeNode *&sp, int lca){
        if(root==NULL) return;
        if(root->val==lca){
            sp = root;
            return;
        }
        findnode(root->right, sp, lca);
        findnode(root->left, sp, lca);
    }
    bool dfs(TreeNode* root, int x, vector <int> &path){
        //if(dfs(right)|| dfs(left)){
            //return true
        //else pop and return false
        if(root==NULL) return false;
        path.push_back(root->val);
        if(root->val==x) return true;
        if(dfs(root->left,x,path) || dfs(root->right,x,path)){
            return true;
        }
        else{
            path.pop_back();
            return false;
        }
    }
    void finddir(TreeNode *root, string &ans, int index, vector<int> &pathdest) {
        for (int i = index; i <pathdest.size(); i++) {
            if(root->left==NULL){
                ans+="R";
                root=root->right;
            }
            else if(root->right==NULL){
                ans+="L";
                root=root->left;
            }
            else{
                if((root->left)->val==pathdest[i]){
                    ans+="L";
                    root=root->left;
                }
                else{
                    ans+="R";
                    root=root->right;
                }
            }
        }
    }
    string getDirections(TreeNode* root, int start, int dest) {
        //lca, find distance to nearest common ancestor
        //dfs from both
        vector <int> pathstart,pathdest;
        dfs(root,start,pathstart);
        dfs(root,dest,pathdest);
        map <int,int> m;
        for(auto &val:pathdest){
            m[val]++;
        }
        int lca;
        reverse(pathstart.begin(),pathstart.end());
        for(auto &val:pathstart){
            if(m.find(val)!=m.end()){
                lca=val;
                break;
            }
        }
        string ans="";
        for(int i=0;;i++){
            if(pathstart[i]==lca){
                break;
            }
            ans+="U";
        }
        TreeNode * sp = NULL;
        findnode(root,sp,lca);
        int index=-1;
        for(int i=0;i<pathdest.size();i++){
            if(pathdest[i]==lca){
                index=i;
                break;
            }
        }
        finddir(sp,ans,index+1,pathdest);
        return ans;
    }
};