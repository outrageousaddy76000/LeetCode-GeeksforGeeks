class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans1=0,ans2=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                ans1--;
                ans2--;
            }
            else if(moves[i]=='R'){
                ans1++;
                ans2++;
            }
            else{
                ans1--;
                ans2++;
            } 
        }
        return max(abs(ans1),abs(ans2));
    }
};