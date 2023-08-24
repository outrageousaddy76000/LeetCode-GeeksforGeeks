class Solution {
public:
    vector<int> ans;
    int n;
    
    void helper(int index, vector<int>& nums, int curr) {
        if (index == n) {
            ans.push_back(curr);
            return;
        }
        
        // Include the current element and move to the next index.
        helper(index + 1, nums, curr ^ nums[index]);
        
        // Exclude the current element and move to the next index.
        helper(index + 1, nums, curr);
    }
    
    int subsetXORSum(vector<int>& nums) {
        n = nums.size();
        helper(0, nums, 0);
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
