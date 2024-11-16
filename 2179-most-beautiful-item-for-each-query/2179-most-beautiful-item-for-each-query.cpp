class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector <int> ans(queries.size());
        sort(items.begin(),items.end());
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }
        for(int i=0;i<queries.size();i++){
            auto it = upper_bound(items.begin(), items.end(), vector<int>{queries[i], INT_MAX}, 
                [](const vector<int>& a, const vector<int>& b) {
                    return a[0] < b[0];
                });

            if (it == items.begin()) {
                ans[i] = 0;
            } else {
                --it;
                ans[i] = (*it)[1];
            }
        }
        return ans;
    }
};