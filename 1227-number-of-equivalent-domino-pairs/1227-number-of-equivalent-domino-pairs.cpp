class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map <pair<int,int>,int> m;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i][0]>dominoes[i][1]){
                swap(dominoes[i][0],dominoes[i][1]);
            }
            m[make_pair(dominoes[i][0],dominoes[i][1])]++;
        }
        int ans=0;
        for(auto &pr:m){
            if(pr.second>1){
                ans+=((pr.second)*(pr.second-1))/2;
            }
        }
        return ans;
    }
};