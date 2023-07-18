class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        return static_cast<double>(accumulate(salary.begin()+1,salary.end()-1,0)/(1.0*(salary.size()-2)));
    }
};