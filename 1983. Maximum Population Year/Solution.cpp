class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector <int> pre(2051);
        for(int i=0;i<logs.size();i++){
            pre[logs[i][0]]++;
            pre[logs[i][1]]--;
        }
        for(int i=1949;i<pre.size();i++){
            pre[i]+=pre[i-1];
        }
        int x = *max_element(pre.begin(),pre.end());
        for(int i=1950;i<=2051;i++){
            if(pre[i]==x) return i;
        }
        return 0;
    }
};