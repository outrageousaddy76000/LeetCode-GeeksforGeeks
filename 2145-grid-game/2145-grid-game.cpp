class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long int ans=LLONG_MAX;
        int n = grid[0].size();
        vector <long long int> pref(n),post(n);
        for(int j=0;j<n;j++){
            if(j) pref[j]=pref[j-1]+grid[1][j];
            else pref[j]=grid[1][j];
        }
        for(int j=n-1;j>=0;j--){
            if(j==n-1) post[j]=grid[0][j];
            else post[j]=post[j+1]+grid[0][j];
        }
        for(int i=0;i<n;i++){
            //i+1 upr ka, i-1 niche ka
            long long int curr1=0,curr2=0;
            if(i+1<n) curr1=post[i+1];
            if(i-1>=0) curr2=pref[i-1];
            ans=min(ans,max(curr1,curr2));
        }
        return ans;
    }
};