class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int totgcd;
        unordered_map <int,int> m;
        for(int i=0;i<deck.size();i++){
            m[deck[i]]++;
            if(i==deck.size()-1) totgcd=m[deck[i]];
        }
        for(auto &pr:m){
            totgcd=gcd(totgcd,pr.second);
        }
        return totgcd!=1;
    }
};