class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> powers;
        long long int num=1;
        string x = to_string(num);
        while(num<1e9){
            x = to_string(num);
            sort(x.begin(),x.end());
            powers.push_back(x);
            num*=2;
        }
        string s = to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<powers.size();i++){
            if(s==powers[i]) return true;
        }
        return false;
    }
};