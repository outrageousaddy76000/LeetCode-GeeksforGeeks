class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //outegree 0
        unordered_map <string,int> m1,m2;
        for(int i=0;i<paths.size();i++){
            m1[paths[i][0]]++;
            m2[paths[i][1]]++;
        }
        string ans="";
        for(auto &pr:m2){
            if(m1.find(pr.first)==m1.end()){
                ans=pr.first;
                break;
            }
        }
        return ans;
    }
};