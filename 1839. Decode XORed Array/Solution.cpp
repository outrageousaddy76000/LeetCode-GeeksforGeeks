class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector <int> v(n+1);
        v[0]=first;
        v[1]=first^encoded[0];
        for(int i=2;i<=n;i++){
            v[i]=v[i-1]^encoded[i-1];
        }
        return v;
    }
};