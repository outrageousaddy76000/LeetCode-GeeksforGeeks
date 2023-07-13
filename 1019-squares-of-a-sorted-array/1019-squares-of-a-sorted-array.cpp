class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        int i=0,j=n-1;
        while(i<=j){
            if(abs(nums[i])<abs(nums[j])){
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
            else{
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};