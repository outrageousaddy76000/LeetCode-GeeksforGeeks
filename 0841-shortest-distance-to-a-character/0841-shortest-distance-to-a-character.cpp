class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector <int> ans(s.size());
        vector <int> ind;
        for(int i=0;i<s.size();i++){
            if(s[i]==c) ind.push_back(i);
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            auto it1 = upper_bound(ind.begin(),ind.end(),i);
            if(it1!=ind.begin()){
                auto it2 = it1-1;
                if(it1!=ind.end())
                    ans[i]=min(abs(*it2-i),abs(*it1-i));
                else ans[i] = abs(*it2-i);
            }
            else{
                ans[i]=abs(*it1-i);
            }
        }
        return ans;
    }
};