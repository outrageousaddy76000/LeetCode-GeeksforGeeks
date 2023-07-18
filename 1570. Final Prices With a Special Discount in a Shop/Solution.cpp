class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector <int> ans(prices.size());
        vector <int> dis(prices.size());
        stack <int> st;
        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(!st.empty()) dis[i]=st.top();
            ans[i]=prices[i]-dis[i];
            st.push(prices[i]);
        }
        return ans;
    }
};