class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans=-1;
        int curr=INT_MAX;
        for(int i=0;i<points.size();i++){
            int a = points[i][0];
            int b = points[i][1];
            if(a==x ||b==y){
                int dist = abs(x-a) + abs(y-b);
                if(dist<curr){
                    ans=i;
                    curr=dist;
                }
            }
        }
        return ans;
    }
};