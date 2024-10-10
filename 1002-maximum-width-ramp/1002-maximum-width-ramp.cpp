class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack <pair<int,int>> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[i]<=st.top().first) st.push(make_pair(nums[i],i));
            else continue;
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top().first){
                ans=max(ans,i-st.top().second);
                st.pop();
            }
            if(st.empty()) break;
        }
        return ans;
    }
};