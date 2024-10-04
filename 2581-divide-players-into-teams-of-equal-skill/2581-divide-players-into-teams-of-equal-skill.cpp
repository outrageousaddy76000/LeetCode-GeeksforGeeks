class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum=0;
        map <int,int> m;
        for(int i=0;i<skill.size();i++){
            sum+=skill[i];
            m[skill[i]]++;
        }
        sum*=2;
        if(sum%skill.size()!=0) return -1;
        int each=sum/skill.size();
        long long int ans=0;
        for(auto &pr:m){
            if(pr.first>each || m[each-pr.first]!=pr.second) return -1;
            ans+=1LL*pr.second*(pr.first*(each-pr.first));
        }
        return ans/2;
    }
};