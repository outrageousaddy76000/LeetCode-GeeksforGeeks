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
    int height(TreeNode *root){
        if(root==NULL) return 0;
        return 1+height(root->left);
    }
    int countNodes(TreeNode* root) {
        int x = height(root);
        if(x<=1) return x;
        int ans = (int)(pow(2,x-1)-1);
        //we have to count the number of nodes in the xth level
        //check the number of children for all nodes at the x-1th level
        queue <pair<TreeNode *,int>> q;
        q.push({root,1});
        while(!q.empty()){
            pair<TreeNode *,int> ptr = q.front();
            q.pop();
            if(ptr.second+1==x){
                if(ptr.first->left!=NULL) ans++;
                if(ptr.first->right!=NULL) ans++;
            }
            else{
                q.push({ptr.first->left,ptr.second+1});
                q.push({ptr.first->right,ptr.second+1});
            }
        }
        return ans;
    }
};