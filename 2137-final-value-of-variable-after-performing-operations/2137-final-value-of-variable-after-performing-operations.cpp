class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(int i=0;i<operations.size();i++){
            if(count(operations[i].begin(),operations[i].end(),'+')>0) ans++;
            else ans--;
        }
        return ans;
    }
};