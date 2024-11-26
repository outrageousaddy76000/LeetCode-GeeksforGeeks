class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if(n==1) return 0;
        vector <int> m(n,0);
        for(auto &val:edges){
            m[val[1]]++;
        }
        int cnt=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(m[i]==0){
                cnt++;
                ans=i;
                if(cnt>1) return -1;
            }
        }
        return ans;
    }
};