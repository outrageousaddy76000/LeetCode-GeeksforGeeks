class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& v) {
        int n = v.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int x = min(v[i][0],v[i][1]);
            ans = max(ans,x);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(min(v[i][0],v[i][1])==ans) res++;
        }
        return res;
    }
};