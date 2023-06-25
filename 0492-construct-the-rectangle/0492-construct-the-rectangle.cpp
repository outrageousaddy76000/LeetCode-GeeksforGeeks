class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector <int> ans(2);
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 1; i <= sqrt(area); i++) {
            if (area % i == 0) {
                ans[0] = area / i;
                ans[1] = i;
            }
        }
        return ans;
    }
};