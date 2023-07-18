class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n =nums.size();
        vector <int> pre(n);
        for(int i=0;i<n;i++){
            if(i) pre[i]=nums[i] +pre[i-1];
            else pre[i]=nums[i];
        }
        int x = *min_element(pre.begin(),pre.end());
        return x>0?1:-1*x + 1;
    }
};