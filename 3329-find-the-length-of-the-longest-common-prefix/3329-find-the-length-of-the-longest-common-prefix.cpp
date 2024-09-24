class Solution {
public:
    int max(int a,int b){
        if(a>b) return a;
        return b;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map <string,int> m;
        for(auto &val:arr1){
            string s = to_string(val);
            for(int i=0;i<s.size();i++) m[s.substr(0,i+1)]++;
        }
        int ans=0;
        for(auto &val:arr2){
            string s = to_string(val);
            for(int i=0;i<s.size();i++){
                string a = s.substr(0,i+1);
                if(m.find(a)!=m.end()) ans=max(ans,a.size());
            }
        }
        return ans;
    }
};