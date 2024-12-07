class Solution {
private:
    int f(int x, vector <int> &nums, int maxOps){
        for(auto &val:nums){
            //subtract from maxOps req to make val = nums
            if(val<=x) continue;
            maxOps-=val/x;
            if(val%x==0){
                maxOps++;
            }
            if(maxOps<0) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=1e9;
        int ans=INT_MAX;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(f(mid,nums,maxOperations)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};