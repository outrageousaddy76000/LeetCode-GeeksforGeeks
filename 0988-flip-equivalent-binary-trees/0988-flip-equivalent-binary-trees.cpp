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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if((root1 && !root2) || (root2 && !root1)) return false;
        if(root1->val!=root2->val) return false;
        bool ans=true;
        //both must have equal number of children
        int cnt1=0,cnt2=0;
        if(root1->left) cnt1++;
        if(root1->right) cnt1++;
        if(root2->left) cnt2++;
        if(root2->right) cnt2++;
        if(cnt1!=cnt2) return false;
        if(cnt1==2){
            bool ans1 = ans;
            bool ans2 = ans;
            bool ans3 = ans;
            bool ans4 = ans;
            ans1 &=flipEquiv(root1->left,root2->left);
            ans2 &=flipEquiv(root1->right,root2->left);
            ans3 &=flipEquiv(root1->left,root2->right);
            ans4 &=flipEquiv(root1->right,root2->right);
            ans = (ans1 && ans4) || (ans2 && ans3);
        }
        else if(cnt1==1){
            if(root1->right && root2->right) ans &= flipEquiv(root1->right,root2->right);
            else if(root1->right && root2->left) ans &= flipEquiv(root1->right,root2->left);
            else if(root1->left && root2->left) ans &= flipEquiv(root1->left,root2->left);
            else ans &= flipEquiv(root1->left,root2->right);
        }
        else ans=true;
        cout<<root1->val<<" "<<root2->val<<" "<<ans<<endl;
        return ans;
    }
};