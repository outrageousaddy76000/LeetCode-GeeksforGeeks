class Solution {
public:
    double trimMean(vector<int>& arr) {
        int p =arr.size()/20;
        sort(arr.begin(),arr.end());
        long long int x = accumulate(arr.begin()+p,arr.end()-p,0);
        cout<<x;
        return (double)((x*1.0)/(arr.size()- 2*p));
    }
};