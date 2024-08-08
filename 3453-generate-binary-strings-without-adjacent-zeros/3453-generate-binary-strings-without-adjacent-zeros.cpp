class Solution {
public:
    vector<string> ans;
    
    void solve(int n, int idx, string tmp, bool lst_one) {
        
        if(idx == n) {
            ans.push_back(tmp);
            return;
        }
        
        if(idx == 0 || lst_one) solve(n, idx+1, tmp + '0', false);
        
        solve(n, idx+1, tmp+'1', true);         
        
    }
    
    vector<string> validStrings(int n) {
        
         // vector<i.//>    
        
        solve(n, 0, "", false);
    
        return ans;
    }
};