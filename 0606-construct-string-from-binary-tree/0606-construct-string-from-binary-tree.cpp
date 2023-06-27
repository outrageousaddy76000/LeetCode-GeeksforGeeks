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
    string ans="";
    void pre(TreeNode *root){
        if(root==NULL) return;
        ans+=to_string(root->val);
        ans+='(';
        pre(root->left);
        ans+=')';
        ans+='(';
        pre(root->right);
        ans+=')';

    }
    string tree2str(TreeNode* root) {
        pre(root);
        string final="";
        for(int i=0;i<ans.size();){
            if(i+3<ans.size() && ans[i]=='(' && ans[i+1]==')' && ans[i+2]=='(' && ans[i+3]==')'){
                //copy none to final
                i+=4;
            }
            else if(i+3<ans.size() && ans[i]=='(' && ans[i+1]==')' && ans[i+2]=='(' &&ans[i+3]!=')'){
                //copy all to final
                final+=ans[i];
                final+=ans[i+1];
                i+=2;
            }
            else if(i+2<ans.size() && ans[i]=='(' && ans[i+1]==')' && ans[i+2]==')'){
                //dont copy
                i+=2;
            }
            else if(ans.size()==i+2 && ans[i]=='(' && ans[i+1]==')'){
                i+=2;
            }
            else {
                final+=ans[i];
                i++;
            }
        }
        cout<<ans;
        return final;
    }
};