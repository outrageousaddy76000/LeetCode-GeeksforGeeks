class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(count(nums.begin(),nums.end(),1)==0) return 0;
        if(count(nums.begin(),nums.end(),0)==0) return nums.size()-1;
        vector <int> len;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                len.push_back(cnt);
                cnt=0;
            }
            else cnt++;
        }
        if(cnt>0)
            len.push_back(cnt);  
        //max sum of two consective elements
        int ans=INT_MIN;
        int n = len.size();
        if(len.size()==1) return len[0];
        for(int i=0;i<n-1;i++){
            ans=max(ans,len[i]+len[i+1]);
        }      
        return ans;
    }
};