class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset <int> s;
        int i=0;
        while(i!=k-1){
            s.insert(nums[i]);
            i++;
        }
        vector <int> ans;
        int cnt=0;
        for(i=k-1;i<nums.size();i++){
            s.insert(nums[i]);
            ans.push_back(*(--s.end()));
            auto it = s.find(nums[cnt]);
            s.erase(it);
            cnt++;
        }
        return ans;
    }
};