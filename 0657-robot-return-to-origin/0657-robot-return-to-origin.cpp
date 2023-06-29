class Solution {
public:
    bool judgeCircle(string moves) {
        vector <int> v(2);
        int n = moves.size();
        for(int i=0;i<n;i++){
            if(moves[i]=='L') v[0]++;
            else if(moves[i]=='D') v[1]++;
            else if(moves[i]=='U') v[1]--;
            else v[0]--;
        }
        return !(v[0] || v[1]);
    }
};