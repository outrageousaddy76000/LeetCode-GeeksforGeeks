class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int t) {
        //put the boxes with most units as long as you can
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a,vector<int> &b){
            if(a[1]==b[1]){
                return a[0]>b[0];
            }
            return a[1]>b[1];
        });
        int ans=0;
        for(auto &val:boxTypes){
            int x = t-val[0];
            if(x<=0){
                ans+=t*val[1];
                break;
            }
            else{
                t-=val[0];
                ans+=val[0]*val[1];
            }
        }
        return ans;
    }
};