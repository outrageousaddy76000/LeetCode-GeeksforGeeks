class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string,int> m1,m2;
        for(int i=0;i<list1.size();i++){
            m1[list1[i]]=i;
        }
        for(int i=0;i<list2.size();i++){
            m2[list2[i]]=i;
        }
        int sum=INT_MAX;
        for(auto &pr:m1){
            if(m2.find(pr.first)!=m2.end()){
                if(pr.second+m2[pr.first]<sum){
                    sum=pr.second+m2[pr.first];
                }
            }
        }
        vector <string> ans;
        for(auto &pr:m1){
            if(m2.find(pr.first)!=m2.end()){
                if(pr.second+m2[pr.first]==sum){
                    ans.push_back(pr.first);
                }
            }
        }
        return ans;
    }
};