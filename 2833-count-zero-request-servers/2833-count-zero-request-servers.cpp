class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        vector <int> ans(queries.size());
        sort(logs.begin(),logs.end(),[](vector <int> &a, vector <int> &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>> time(queries.size());
        for(int i = 0;i<queries.size();i++) time[i] = {queries[i],i};
        sort(time.begin(),time.end());
        //n-server that got requests
        int i=0,j=0;
        unordered_map <int,int> mp;
        for(auto [end,index]:time){
            int start = max(end-x,0);
            // <------>
            //   <------>
            while(i<m && logs[i][1]<=end){
                mp[logs[i][0]]++;
                i++;
            }
            while(j<m && logs[j][1]<start){
                mp[logs[j][0]]--;
                if(mp[logs[j][0]]==0) mp.erase(logs[j][0]);
                j++;
            }
            ans[index]=n-mp.size();
        }
        return ans;
    }
};