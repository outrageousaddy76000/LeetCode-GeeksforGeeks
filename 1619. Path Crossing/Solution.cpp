class Solution {
public:
    bool isPathCrossing(string path) {
        set <pair<int,int>> s;
        int x =0,y=0;
        s.insert({0,0});
        for(int i=0;i<path.size();i++){
            int a = s.size();
            if(path[i]=='N') y++;
            if(path[i]=='S') y--;
            if(path[i]=='E') x++;
            if(path[i]=='W') x--;
            s.insert({x,y});
            if(a==s.size()) return true;
        }
        return false;
    }
};