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
    vector <int> sorted;
    void in(TreeNode *root){
        if(root==NULL) return;
        in(root->left);
        sorted.push_back(root->val);
        in(root->right);
    }
    bool findTarget(TreeNode* root, int target) {
        in(root);
        int n = sorted.size();
        int i=0,j=n-1;
        while(j>i){
            if(sorted[i]+sorted[j]>target){
                j--;
            }
            else if (sorted[i]+sorted[j]<target){
                i++;
            }
            else return true;
        }
        return false;
    }
};