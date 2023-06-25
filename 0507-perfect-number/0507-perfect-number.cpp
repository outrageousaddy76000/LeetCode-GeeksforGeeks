class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector <int> div;
        for(int i=1;i<=num/2;i++){
            if(num%i==0) div.push_back(i);
        }
        long long int sum = accumulate(div.begin(),div.end(),0);
        if(sum==num) return true;
        return false;
    }
};