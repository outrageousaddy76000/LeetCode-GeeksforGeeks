class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector <int> ans;
        deque <int> dq;
        for(int i=0;i<=s.size();i++){
            dq.push_back(i);
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                ans.push_back(dq[0]);
                dq.pop_front();
            }
            else{
                ans.push_back(dq[dq.size()-1]);
                dq.pop_back();
            }
        }
        ans.push_back(dq[0]);
        return ans;
    }
};