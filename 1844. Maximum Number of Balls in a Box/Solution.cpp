class Solution {
public:
    int countBalls(int low, int high) {
        unordered_map <int,int> m;
        for(int i=low;i<=high;i++){
            int x = i;
            int sum=0;
            while(x>0){
                sum+=x%10;
                x/=10;
            }
            m[sum]++;
        }
        int ans = INT_MIN;
        for(auto &pr:m){
            ans = max(ans,pr.second);
        }
        return ans;
    }
};