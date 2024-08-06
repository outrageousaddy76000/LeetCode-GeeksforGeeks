class Solution {
public:
    int solve(int index, vector <int> &days, vector <int> &costs, vector <int> &dp){
        if(index>=days.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        //buy of all costs
        //buy 1 day pass
        int d1 = costs[0]+solve(index+1,days,costs,dp);
        //buy 7 day pass
        int next1= upper_bound(days.begin()+index,days.end(),days[index]+6)-days.begin();
        int d2 = costs[1]+solve(next1,days,costs,dp);
        //buy 30 day pass
        int next2 = upper_bound(days.begin()+index,days.end(),days[index]+29)-days.begin();
        int d3 = costs[2]+solve(next2,days,costs,dp);
        return dp[index]=min(d1,min(d2,d3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp(days.size(),-1);
        return solve(0,days,costs,dp);
    }
};