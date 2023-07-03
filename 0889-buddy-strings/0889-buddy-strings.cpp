class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size() || s.size()<=1) return false;
        int cnt=0;
        int ind1=-1,ind2=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                cnt++;
                if(ind1==-1) ind1=i;
                else ind2=i;
                if(cnt>2) return false;
            }
        }
        if(ind1==-1 || ind2==-1){
            if(ind1!=-1) return false;
            //a==b case
            unordered_map <int,int> m;
            for(int i=0;i<s.size();i++){
                m[s[i]]++;
            }
            for(auto &pr:m){
                if(pr.second>1) return true;
            }
            return false;
        }
        if(s[ind1]==goal[ind2] && s[ind2]==goal[ind1]) return true;
        return false;
    }
};