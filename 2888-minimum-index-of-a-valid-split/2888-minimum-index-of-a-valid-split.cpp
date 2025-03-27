class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //length of the array, number of most frequent element, n - length of array, number of most frequent array
        int maxi=-1;
        int x;
        map <int,int> m;
        for(auto &val:nums){
            m[val]++;
            if(m[val]>maxi){
                maxi=m[val];
                x = val;
            }
        }
        //only x can be that element
        int curr_freq=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x) curr_freq++;
            int curr_length = i+1;
            int rem_length = nums.size()-i-1;
            int rem_freq = m[x]-curr_freq;
            // cout<<curr_length<<" "<<curr_freq<<" "<<rem_length<<" "<<rem_freq<<endl;
            if(2*curr_freq>curr_length && 2*rem_freq>rem_length) return i;
        }
        return -1;
    }
};