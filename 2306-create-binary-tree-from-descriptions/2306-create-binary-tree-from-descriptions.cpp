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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map <int,TreeNode *> m;
        map <int,int> findroot;
        for(auto &val:descriptions){
            int parent = val[0];
            int child = val[1];
            findroot[child]--;
            if(m.find(parent)!=m.end()){
                //parent has been created already
                TreeNode *p = m[parent];
                if(m.find(child)!=m.end()){
                    //child also created so link the parent and child
                    TreeNode *c = m[child];
                    if(val[2]==1) p->left = c;
                    else p->right = c;
                }
                else{
                    //create child and add to map and then link the parent and child
                    TreeNode *c = new TreeNode(child);
                    m[child] = c;
                    if(val[2]==1) p->left = c;
                    else p->right = c;
                }
            }
            else{
                //parent has not been created, create it and add to map
                TreeNode *p = new TreeNode(parent);
                m[parent] = p;
                if(m.find(child)!=m.end()){
                    //child also created so link the parent and child
                    TreeNode *c = m[child];
                    if(val[2]==1) p->left = c;
                    else p->right = c;
                }
                else{
                    //create child and add to map and then link the parent and child
                    TreeNode *c = new TreeNode(child);
                    m[child] = c;
                    if(val[2]==1) p->left = c;
                    else p->right = c;
                }
            }
        }
        TreeNode *ans = NULL;
        for(auto &pr:m){
            if(findroot.find(pr.first)==findroot.end()){
                ans = pr.second;
                break;
            }
        }
        return ans;
    }
};