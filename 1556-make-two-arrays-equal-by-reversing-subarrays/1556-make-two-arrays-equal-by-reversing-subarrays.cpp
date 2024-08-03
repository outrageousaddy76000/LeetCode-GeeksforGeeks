class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        //if they are same when sorted
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        return target == arr;
    }
};