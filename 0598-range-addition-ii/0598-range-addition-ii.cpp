class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        //min common
        int minx=INT_MAX;
        int miny=INT_MAX;
        if(ops.size()==0) return m*n;
        for(int i=0;i<ops.size();i++){
            minx=min(ops[i][0],minx);
            miny=min(ops[i][1],miny);
        }
        return 1LL*minx*1LL*miny;
    }
};