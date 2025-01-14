class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector <int> ans;
        set <int> s;
        for(int i=0;i<A.size();i++){
            s.insert(A[i]);
            s.insert(B[i]);
            ans.push_back(2*(i+1) - s.size());
        }
        return ans;
    }
};