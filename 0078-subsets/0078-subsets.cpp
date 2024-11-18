class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector <int> &nums,int index, vector <int> curr){
        if(index==nums.size()){
            ans.push_back(curr);
            return;
        }
        //backtrack logic
        //dont take
        solve(nums,index+1,curr);
        //take
        curr.push_back(nums[index]);
        solve(nums,index+1,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //take or not take, when reach nth index, push
        vector <int> curr;
        ans.clear();
        solve(nums,0,curr);
        return ans;
    }
};