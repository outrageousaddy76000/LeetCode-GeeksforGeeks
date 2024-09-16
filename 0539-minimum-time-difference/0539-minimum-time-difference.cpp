class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //store in terms of minutes passed since 00:00
        vector <int> times;
        for(auto &s:timePoints){
            int h = stoi(s.substr(0,2),0,10);
            int m = stoi(s.substr(3,2),0,10);
            times.push_back(h*60+m);
        }
        sort(times.begin(),times.end());
        int ans=INT_MAX;
        for(int i=1;i<times.size();i++){
            ans=min(ans,times[i]-times[i-1]);
        }
        //for last and first, take reverse time as well
        ans=min(ans,times[0]+24*60-times[times.size()-1]);
        return ans;
    }
};