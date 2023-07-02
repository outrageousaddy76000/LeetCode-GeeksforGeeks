class Solution {
public:
    bool check(int n){
        int a = n;
        while(n>0){
            int x = n%10;
            if(x==0 || a%x!=0) return false;
            n/=10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> ans;
       for(int i=left;i<=right;i++){
           if(check(i)) ans.push_back(i);
       }
       return ans;
    }
};