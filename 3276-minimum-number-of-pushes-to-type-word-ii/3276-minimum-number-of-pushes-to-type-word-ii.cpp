class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> m1;
        for(char &c:word) m1[c]++;
        vector<pair<int,char>> v;
        for(auto &pr:m1) v.push_back({pr.second,pr.first});
        sort(v.rbegin(),v.rend());
        int cnt=0;
        int ans=0;
        for(auto &val:v){
            if(cnt>=24){
                ans+=val.first*4;
            }
            else if(cnt>=16){
                ans+=val.first*3;
            }
            else if(cnt>=8){
                ans+=val.first*2;
            }
            else{
                ans+=val.first;
            }
            cnt++;
        }
        return ans;
    }
};