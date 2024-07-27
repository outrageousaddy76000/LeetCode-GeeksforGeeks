class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        //fill initial edges
        for(int i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a']=min(dist[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i])
                if(dist[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
                else ans+=dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};