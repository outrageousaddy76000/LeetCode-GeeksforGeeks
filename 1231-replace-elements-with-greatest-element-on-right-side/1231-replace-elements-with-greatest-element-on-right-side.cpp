class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatest_right=-1;
        int new_greatest_right=INT_MIN;
        for(auto it = arr.rbegin();it<arr.rend();it++){
            //store new greatest right
            new_greatest_right=max(new_greatest_right,*it);
            *it=greatest_right;
            greatest_right=max(greatest_right,new_greatest_right);
        }
        return arr;
    }
};