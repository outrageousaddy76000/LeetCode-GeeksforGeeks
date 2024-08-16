class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        vector <pair<int,int>> mini,maxi;
        for(int i=0;i<arr.size();i++){
            mini.push_back({arr[i][0],i});
            maxi.push_back({arr[i][arr[i].size()-1],i});
        }
        sort(mini.begin(),mini.end());
        sort(maxi.begin(),maxi.end());
        if(mini[0].second==maxi[maxi.size()-1].second){
            return max(abs(maxi[maxi.size()-1].first - mini[1].first),abs(maxi[maxi.size()-2].first-mini[0].first));
        }
        return maxi[maxi.size()-1].first-mini[0].first;
    }
};