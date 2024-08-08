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
    int findMaxIndex(int start, int end,vector <int> &nums){
        int ans;
        int maxi = -1; //since all elements are >= 0
        for(int i=start;i<=end;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                ans = i;
            }
        }
        return ans;
    }
    TreeNode* helper(vector <int> &nums, int start, int end){
        int index = findMaxIndex(start,end,nums);
        TreeNode* root = new TreeNode(nums[index]); 
        //index+1 to end, start to index-1
        if(index-1>=start){
            root->left = helper(nums,start,index-1);
        }
        if(index+1<=end){
            root->right = helper(nums,index+1,end);
        }
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* ans = helper(nums,0,nums.size()-1);
        return ans;
    }
};