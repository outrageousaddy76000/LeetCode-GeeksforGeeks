class Solution {
public:
    int countVowelStrings(int n) {
        vector <int> prev(5,1);
        vector <int> curr = prev;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=5;j++){
                curr[j-1]=accumulate(prev.begin(),prev.begin()+j,0);
            }
            prev=curr;
        }
        return accumulate(curr.begin(),curr.end(),0);
    }
};