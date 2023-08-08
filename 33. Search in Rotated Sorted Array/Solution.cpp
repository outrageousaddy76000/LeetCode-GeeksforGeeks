class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int index=0;
        unordered_map <int,int> m;
        for(int i=1;i<n;i++){
            if(m.find(nums[i])==m.end())
                m[nums[i]]=i;
            if(nums[i]<nums[i-1]){
                index=i;
            }
        }
        rotate(nums.begin(),nums.begin()+index,nums.end());
        for(auto &val:nums) cout<<val<<" ";
        int high=n-1,low=0;
        while(high>=low){
            int mid = low+ (high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else return m[nums[mid]];
        }
        return -1;
    }
};