class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        
        // Custom comparator to sort the strings in the correct order
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string ans="";
        for(auto &val:strs){
            ans+=val;
        }
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};