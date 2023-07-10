class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map <char,int> m;
        for(int i=0;i<licensePlate.size();i++){
            if(licensePlate[i]==' ' || (licensePlate[i]<=57 && licensePlate[i]>=48))
                continue;
            m[tolower(licensePlate[i])]++;
        }
        vector <pair<int,pair<int,string>>> v(words.size());
        for(int i=0;i<words.size();i++){
            v[i].first=words[i].size();
            v[i].second.first=i;
            v[i].second.second=words[i];
        }
        sort(v.begin(),v.end());
        for(auto &val:v){
            string s = val.second.second;
            unordered_map <char,int> x;
            x=m;
            for(int i=0;i<s.size();i++){
                x[s[i]]--;
                if(x[s[i]]<=0) x.erase(s[i]);
                if(x.size()==0) return s;
            }
        }
        return words[0];
    }
};