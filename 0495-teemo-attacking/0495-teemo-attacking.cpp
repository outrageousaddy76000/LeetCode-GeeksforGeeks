class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        int mini = -1;
        for(int i=0;i<timeSeries.size();i++){
            if(timeSeries[i]>mini){
                ans+=duration;
            }
            else{
                ans-=(mini-timeSeries[i]+1);
                ans+=duration;
            }
            mini=timeSeries[i]+duration-1;
        }
        return ans;
    }
};