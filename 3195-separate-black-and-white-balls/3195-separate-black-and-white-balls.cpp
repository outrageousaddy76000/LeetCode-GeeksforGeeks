class Solution {
public:
    long long minimumSteps(string s) {
        //final string will be 000...111
        vector <int> indeces;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') indeces.push_back(i);
        }
        long long int ans=0;
        for(int i=0;i<indeces.size();i++){
            ans+=indeces[i]-i;
        }
        return ans;
    }
};