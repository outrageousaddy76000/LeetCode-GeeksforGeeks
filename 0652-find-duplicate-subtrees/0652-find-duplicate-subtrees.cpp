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
    vector <TreeNode*> ans;
    unordered_map <string,int> mp;
    string findAns(TreeNode* root){
        if(!root) return "";
        string curr=to_string(root->val);
        curr+="L";
        curr+=findAns(root->left);
        curr+="R";
        curr+=findAns(root->right);
        mp[curr]++;
        if(mp[curr]==2) ans.push_back(root);
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ans.clear();
        mp.clear();
        findAns(root);
        return ans;
    }
};