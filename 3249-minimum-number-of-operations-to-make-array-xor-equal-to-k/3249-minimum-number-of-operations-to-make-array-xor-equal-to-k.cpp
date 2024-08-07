class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        int ans=0;
        for(auto val:nums){
            ans=ans^val;
        }
        bitset<32> b1(ans);
        bitset<32> b2(k);
        for(int i=0;i<32;i++){
            if(b1[i]!=b2[i]) cnt++;
        }
        return cnt;
    }
};